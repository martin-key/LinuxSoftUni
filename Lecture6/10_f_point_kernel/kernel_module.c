#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>


static int __init init(void)
{
	int side = 11;
	int asd = 2;
	int numberOfAsd = 3;
	int result = side*side*side;
	int i;
	int base = 10;
	int number = 1;

	for(i = 0; i < asd * numberOfAsd; i++)
	{
		number *= base;
	}

	printk(KERN_INFO "Variant 1 %d.%d\n",result/(number),
						 result%(number));

//	kernel_fpu_begin();
//	float resultFloat = (side*side*side)/(10 * resultFloatingSigns);
//	printk(KERN_INFO "Variant 2 %f\n", resultFloat);
//	kernel_fpu_end();
	
	return 0;
}

static void __exit cleanup(void)
{
	printk("End of calc\n");
}

module_init(init);
module_exit(cleanup);

