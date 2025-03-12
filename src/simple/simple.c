#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

#include <linux/hash.h> 
#include <linux/gcd.h> 

#include <asm/param.h>
#include <linux/jiffies.h>

/* This function is called when the module is loaded. */
int simple_init(void) {
    printk(KERN_INFO "Loading Kernel Module\n");

    printk(KERN_INFO "%lu\n", GOLDEN_RATIO_PRIME);

    printk(KERN_INFO, "Jiffies: %lu\t\tHZ: %lu\n", jiffies, HZ);

    return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) {
    printk(KERN_INFO "Removing Kernel Module\n");

    unsigned long result = gcd(3300, 24);
    printk(KERN_INFO "gcd(3300, 24) = %lu\n", result);
    printk(KERN_INFO, "Jiffies: %lu\n", jiffies);


    

}

/* Macros for registering module entry and exit points. */
module_init(simple_init);
module_exit(simple_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("Andrew Lin");
