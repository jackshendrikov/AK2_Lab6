#include <linux/ktime.h>
#pragma once

struct head_list {
	struct head_list *next;
	ktime_t start_time;
	ktime_t finish_time;
};

int hello_print(uint count); 
