/*
 *  hello−1.c − The simplest kernel module.
 */
#include <linux/module.h>       /* Needed by all modules */
#include <linux/kernel.h>       /* Needed for KERN_INFO */
#include <linux/init.h>

int init(void)
{

printk(KERN_INFO "Hello world 1.\n");
return 0;
}
/*
 * A non 0 return means init_module failed; module can't be loaded.
 */
void exit(void)
{
printk(KERN_INFO "Goodbye world 1.\n");
}

module_init(init);
module_exit(exit);
