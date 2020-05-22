/* I pledge my honor that I have abided by the Stevens Honor System
 *	Brandon Patton
 */

#include <linux/syscalls.h>
#include <linux/sched.h>
#include <linux/kernel.h>
#include <asm/uaccess.h>

#define MAX_STRING_LEN 128

SYSCALL_DEFINE2(my_syscall2, char *, inp, char *, outp){
	if (strlen(inp) > MAX_STRING_LEN){
		printk(KERN_INFO "Input string too long: %d\n", -1);
		return -1;
	} else {
		int result, i;
		char buffer[MAX_STRING_LEN];
		printk(KERN_INFO "Input: %s\n", inp);
		copy_from_user(buffer, inp, MAX_STRING_LEN);
		while(i <= strlen(inp)){
			if (buffer[i] == "o"){
				buffer[i] = "0";
				result += 1;
			} else {
				i++;
			}
			i++;
		}
		copy_to_user(outp, buffer, MAX_STRING_LEN); 
		printk(KERN_INFO "Output: %s\n", buffer);
		printk(KERN_INFO "Pid: %d\n", current->pid);
		printk(KERN_INFO "Result: %d\n", result);
		return result;
	}
}
