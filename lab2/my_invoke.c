
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <linux/sched.h>

#define SYS_my_syscall 548
#define SYS_my_syscall2 549

int main(int argc, char **argv){
	printf("Brandon Patton  Pid: %d\n");
	int x = 3;
	int y = 2;
	printf("Arguments for sum: %d,%d\n", x, y);
	long res = syscall(SYS_my_syscall, x, y);
       	printf("Returned sum: %d\n", res);
	//char string[] = "I have been one acquainted with the night.";
	//printf("Arguments for string replacement: %s\n", string);
	//long result = syscall(SYS_my_syscall2, string);
	//printf("Returned string: %d\n", result);
	char tooLong[] = ";alsdkjf;lakdsnv;ladsijf;oiejr;iewj;iweur;oiwejf;liajf;oaisdugoasijdf;liadsjf;aifdg;ewajf;isadjf;auhg;saidjf;lsadifjdsauhf;adsifj;lsadijfo;saduhfadshfj;laisdfj;osadihf;sadfjj;lasidjf;asidhhfkadshf;alsdijfasdjfoasdhf;lasidjf;asidjfasuhdv;cvn;oiuodsiafjhekhf";
	long resultLong = syscall(SYS_my_syscall2, tooLong);
	printf("This should return -1: %d\n", resultLong); 
	return 0;
}
