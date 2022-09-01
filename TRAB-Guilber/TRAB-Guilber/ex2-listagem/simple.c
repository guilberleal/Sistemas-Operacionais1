#include <linux/module.h>
#include <linux/sched/signal.h>
#include <linux/sched.h>

struct task_struct *tarefa;

int simple_init(void){
	printk(KERN_INFO "Loading Kernel Module\n");
	for_each_process( tarefa ){
		printk(KERN_INFO"\nCOMANDO = %s, ESTADO = %ld, PID = %d\n",tarefa->comm, tarefa->state, tarefa->pid);
	}
	return 0;
}

void simple_exit(void){
	printk(KERN_INFO "Removing Kernel Module \n");
	
}
module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("Leal");

