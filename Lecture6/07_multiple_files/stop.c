#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>


void exit_function(void)
{
	printk(KERN_INFO "Hello from the other fileeee nana-nan-nanan\n");
}


