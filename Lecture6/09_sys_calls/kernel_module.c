#include <linux/kernel.h>
#include <linux/module.h>

#include <linux/syscalls.h>
#include <linux/sched.h>

#include <asm/uaccess.h>

extern void *sys_call_table[];

MODULE_PARM(uid, "i");

asmlinkage int (*original_call)(const char *, int, int);

asmlinkage int (*getuid_call)();

asmlinkage int our_sys_open(const char *filename,int flags, int mode)
{
  	int i = 0;
  	char ch;
	if (uid == getuid_call()) 
	{
		printk("Opened file by %d: ", uid); 
    		do 
		{
			get_user(ch, filename+i);
			i++;
      			printk("%c", ch);
    		} while (ch != 0);
	return original_call(filename, flags, mode);

}


int init_module()
{
  /* Warning - too late for it now, but maybe for 
   * next time... */
  printk("I'm dangerous. I hope you did a ");
  printk("sync before you insmod'ed me.\n");
  printk("My counterpart, cleanup_module(), is even"); 
  printk("more dangerous. If\n");
  printk("you value your file system, it will ");
  printk("be \"sync; rmmod\" \n");
  printk("when you remove this module.\n");

  /* Keep a pointer to the original function in 
   * original_call, and then replace the system call 
   * in the system call table with our_sys_open */
  original_call = sys_call_table[__NR_open];
  sys_call_table[__NR_open] = our_sys_open;

  /* To get the address of the function for system 
   * call foo, go to sys_call_table[__NR_foo]. */

  printk("Spying on UID:%d\n", uid);

  /* Get the system call for getuid */
  getuid_call = sys_call_table[__NR_getuid];

  return 0;
}


/* Cleanup - unregister the appropriate file from /proc */
void cleanup_module()
{
  /* Return the system call back to normal */
  if (sys_call_table[__NR_open] != our_sys_open) {
    printk("Somebody else also played with the ");
    printk("open system call\n");
    printk("The system may be left in ");
    printk("an unstable state.\n");
  }

  sys_call_table[__NR_open] = original_call;
}  


