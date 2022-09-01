#include <linux/module.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/init.h>


struct task_struct *aux; //cria struct aux pra receber retorno de list_entry 
struct list_head *list; //aponta para cabeca da lista.

	
void funcBusca(struct task_struct *tarefa){

	printk(KERN_INFO"\nCOMANDO = %s, ESTADO = %ld, PID = %d\n",tarefa->comm, tarefa->state, tarefa->pid);
	
	list_for_each(list, &tarefa->children){
		aux = list_entry(list, struct task_struct, sibling);
		funcBusca(aux); //funcao rebece aux "list_entry"
	}
}
int simple_init(void){
	printk(KERN_INFO "Loading Kernel Module\n");
	funcBusca(&init_task);
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

