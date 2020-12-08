#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/printk.h>
#include <linux/slab.h>

#include <hello1.h>

MODULE_AUTHOR("Jack Shendrikov <jackshen@ukr.net>");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");
MODULE_VERSION("2.0");

static struct head_list *head = NULL;

int free_list(int print_smth) {
	struct head_list *tmp;
	
	if (ZERO_OR_NULL_PTR(head)) return 0;
	
	while (head != NULL) {
		tmp = head;
		if (print_smth) pr_info("Printing time: %lld", tmp->finish_time - tmp->start_time);
		head = tmp->next;
		kfree(tmp);
	}
	
	if (!ZERO_OR_NULL_PTR(head)) return -EAGAIN;
	
	pr_info("Module removed!");
	pr_info("");
	return 0;
}

int hello_print(uint count) {
	uint i = 0;
	struct head_list **tmp1, **tmp2;
	
	if (!ZERO_OR_NULL_PTR(head))
		if (free_list(0) != 0)
			return -EAGAIN;
	
	tmp1 = &head;
	
	
	if (!count) {
		pr_warning("The parameter is 0. You cannot enter 0.");
	} 
	
	if (count >= 5 && count <= 10) {
		pr_warning("The parameter is %d, between [5;10], enter number less than 5", count);
	} else if (count > 10) {
		pr_err("The parameter is %d, (> 10)", count);
		return -EINVAL;
	} 

	for (i = 0; i < count; i++) {
		*tmp1 = kmalloc(sizeof(struct head_list), GFP_KERNEL);
		if (ZERO_OR_NULL_PTR(*tmp1)) goto error;
		
		(*tmp1)->next = NULL;
		(*tmp1)->start_time = ktime_get();
		pr_info("Hello, World!\n");
		(*tmp1)->finish_time = ktime_get();
		tmp2 = tmp1;
		tmp1 = &(*tmp1)->next;
	}
	
	return 0;

error:
	pr_err("Out of memory!\n");
	free_list(0);
	return -ENOMEM;
}

EXPORT_SYMBOL(hello_print);

static int __init hello_init(void) {
	return 0;
}

static void __exit hello_exit(void) {
	free_list(1);
}

module_init(hello_init);
module_exit(hello_exit);	

