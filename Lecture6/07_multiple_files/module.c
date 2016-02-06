#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_AUTHOR("Martin Kuvandzhiev");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Takes as arguments myArg and myArray just to print them back");
int init_function(void);
void exit_function(void);

int __init initialize(void)
{
	init_function();
	return 0;
}

void __exit cleanup(void)
{
	exit_function();
}


module_init(initialize);
module_exit(cleanup);
