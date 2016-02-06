#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

int init_function(void)
{
	printk(KERN_ALERT "Hello .... it's me\n");
	return 0;
}
