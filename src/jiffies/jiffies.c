#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <asm/uaccess.h>


#include <linux/jiffies.h>

#define BUFFER_SIZE 32
#define PROC_NAME "jiffies"

ssize_t proc_read(struct file *file, char __user *usr_buf,size_t count, loff_t *pos);
// static struct file_operations proc_ops_ = {
// .owner = THIS_MODULE,
// .read = proc_read,
// };



static const struct proc_ops proc_ops_ = {
    // .proc_open = skynet_open,
    .read = seq_read,
    // .proc_lseek = seq_lseek,
    // .proc_release = single_release,
  };
/* This function is called when the module is loaded. */
int proc_init(void) {
    /* creates the /proc/hello entry */
    proc_create(PROC_NAME, 0666, NULL, &proc_ops_);
    // proc_create_single(PROC_NAME, 0666, NULL, proc_read);
    return 0;
}

/* This function is called when the module is removed. */
void proc_exit(void) { 
    /* removes the /proc/hello entry */
    remove_proc_entry(PROC_NAME, NULL);
}

/* This function is called each time /proc/hello is read */
ssize_t proc_read(struct FILE *file, char __user *usr_buf, size_t count, loff_t *pos) {
    int rv = 0;
    char buffer[BUFFER_SIZE];
    static int completed = 0;
    if (completed) {
        completed = 0;
        return 0;
    }
    completed = 1;

    // Convert number of jiffies to string.
    rv = sprintf(buffer, "%lu\n", jiffies);
    
    /* copies kernel space buffer to user space usr_buf */
    copy_to_user(usr_buf, buffer, rv);
    return rv;
}

module_init(proc_init);
module_exit(proc_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Jiffies Module");
MODULE_AUTHOR("Andrew Lin");
    