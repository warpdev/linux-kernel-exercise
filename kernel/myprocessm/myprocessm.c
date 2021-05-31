#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>

void (*hook_fork_p)(struct task_struct*);
void (*hook_exit_p)(struct task_struct*);

static int mPID = 1;

module_param(mPID, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(mPID, "process PID");

static int hello_init(void)
{
	struct task_struct *p;

	p = pid_task(find_vpid(mPID), PIDTYPE_PID);
	printk("info : pid = %d, state = %ld, comm = %s\n", p->pid, p->state, p->comm);
	
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "Test exit\n");
}


//EXPORT_SYMBOL(hook_fork);

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("warp26");
MODULE_DESCRIPTION("Hello world for Linux Kernel module.");
