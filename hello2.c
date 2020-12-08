#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/printk.h>

#include <hello1.h>

MODULE_AUTHOR("Jack Shendrikov <jackshen@ukr.net>");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");
MODULE_VERSION("2.0");

static uint count = 1;
module_param(count, uint, S_IRUGO);
MODULE_PARM_DESC(count, "Count to print 'Hello, world!'");

static int __init hello_init(void) {
	return hello_print(count);
}

static void __exit hello_exit(void) {
	/* do nothing */
}

module_init(hello_init);
module_exit(hello_exit);	
