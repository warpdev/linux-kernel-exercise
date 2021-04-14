#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>

void (*hook_fork_p)(struct task_struct*);
void (*hook_exit_p)(struct task_struct*);

void hook_fork(struct task_struct* p)
{
	printk("fork: pid = %d, state = %ld, comm = %s\n", p->pid, p->state, p->comm);
}

void hook_exit(struct task_struct* p)
{
	printk("exit: pid = %d, state = %ld, comm = %s\n", p->pid, p->state, p->comm);
}

static int hello_init(void)
{
	struct task_struct *p;
	p=get_current();
	
	hook_fork_p = hook_fork;
	hook_exit_p = hook_exit;

	printk("Kernel Message] : Current Process\n");
	printk("pid = %d, state = %ld, comm = %s\n", p->pid, p->state, p->comm);
	printk(KERN_ALERT "Test\n");
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
