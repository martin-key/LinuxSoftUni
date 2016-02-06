#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_AUTHOR("Martin Kuvandzhiev");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Takes as arguments myArg and myArray just to print them back");

int myArg=0;
module_param(myArg, int, 0);
MODULE_PARM_DESC(myArg,"Integer parameter");
int myArray[6] = {0,1,2,3,4,5};
int count = 0;
module_param_array(myArray, int, &count, 0);
MODULE_PARM_DESC(myArray,"Integer array");
MODULE_PARM_DESC(count,"Number of elements in myArray");

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
