#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <asm/uaccess.h>

#include <asm/param.h>
#include <linux/jiffies.h>

#define BUFFER_SIZE 32
#define PROC_NAME "seconds"

ssize_t proc_read(struct file *file, char __user *usr_buf,size_t count, loff_t *pos);
static struct proc_ops proc_ops_ = {
.read = proc_read,
};

/* This function is called when the module is loaded. */
int proc_init(void) {
    /* creates the /proc/hello entry */
    proc_create(PROC_NAME, 0666, NULL, &proc_ops_);
    printk(KERN_INFO "Loaded seconds Module\n");

    return 0;
}

/* This function is called when the module is removed. */
void proc_exit(void) { 
    /* removes the /proc/hello entry */
    remove_proc_entry(PROC_NAME, NULL);
}

/* This function is called each time /proc/hello is read */
ssize_t proc_read(struct file *file, char __user *usr_buf, size_t count, loff_t *pos) {
    int rv = 0;
    char buffer[BUFFER_SIZE];
    static int completed = 0;
    if (completed) {
        completed = 0;
        return 0;
    }
    completed = 1;

    // Calculate the number of seconds. 
    // Jiffies is the number of timer interrupts that have occured since boot.
    // HZ is the number of timer interrupts per second.
    float seconds = ((float) jiffies) / HZ;
 
    // Convert uptime to string.
    rv = sprintf(buffer, "%f\n", seconds);
    
    /* copies kernel space buffer to user space usr_buf */
    copy_to_user(usr_buf, buffer, rv);
    return rv;
}

module_init(proc_init);
module_exit(proc_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Seconds Module");
MODULE_AUTHOR("Andrew Lin");
    