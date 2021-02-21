# AK-2 | Lab Work #6
Allocating Memory in the Linux Kernel

### Task:
> - Declare a data structure for placement in a list that contains a field of type `ktime_t` in addition to the `struct list_head` element (include /linux/ktime.h in your linux-stable repository).
> - Create a static list header variable.
> - Before each greeting print, allocate memory for an instance of the declared structure, write in it the current kernel time obtained by the `ktime_get()` function.
> - In the `hello_exit()` function, go through the list and print the time of each event in nanoseconds, remove the list item and free the allocated memory.
> - At this stage, it is enough to allocate memory by calling `ptr = kmalloc(sizeof(*ptr), GFP_KERNEL);` and free it by calling `kfree(ptr);`
> - Also add another field of type `ktime_t` and record the time before and after calling the print function, and on unloading of the module print the time spent on each print.
