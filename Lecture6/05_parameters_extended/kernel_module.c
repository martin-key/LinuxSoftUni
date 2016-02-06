#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

int myArg=0;
module_param(myArg, int, 0);

int myArray[6] = {0,1,2,3,4,5};
int count = 0;
module_param_array(myArray, int, &count, 0);

static int __init hello_init(void)
{
	printk(KERN_INFO "Some integer = %d", myArg);
	int i;
	for (i = 0; i < count; i++)
	{
		printk(KERN_INFO "myArray[%d] = %d\n", i, myArray[i]);
	}
	
	return 0;
}


static void __exit hello_exit(void)
{
	printk(KERN_INFO "Goodbye cruel world\n");
}


module_init(hello_init);
module_exit(hello_exit);
