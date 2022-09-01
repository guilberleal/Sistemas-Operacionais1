#include <linux/module.h>
#include <linux/jiffies.h>
#include <asm/param.h>

unsigned long a, b, t;
int simple_init(void){
	printk(KERN_INFO "Loading Kernel Module\n");
	int interrupcao = HZ;
	a = jiffies;
	printk(KERN_INFO "O Valor de HZ = %d\n", interrupcao);
	printk(KERN_INFO "O Valor de jiffies = %lu\n", a);
	return 0;
}

void simple_exit(void){
	b = jiffies;
	printk(KERN_INFO "O Valor de jiffies = %lu\n", b);
	t = ( b - a)/HZ;
	printk(KERN_INFO "Tempo Total em segundos = %lu \n", t);
	
	printk(KERN_INFO "Removing Kernel Module \n");

}

module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("Leal");

