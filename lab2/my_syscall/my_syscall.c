/* I pledge my honor that I have abided by the Stevens Honor System
 *	Brandon Patton
 */

#include <linux/syscalls.h>
#include <linux/sched.h>
#include <linux/kernel.h>
#include <asm/uaccess.h>

SYSCALL_DEFINE2(my_syscall, int, x, int, y) {
	printk(KERN_INFO "Pid: %d\n", current->pid);
	printk(KERN_INFO "my_syscall(%d,%d) = %d\n", x, y, x+y);
	return x+y;
}
