#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
void print_id();
int
main(int argc,char *argv[])
{
	int pid;
	if((pid =fork())<0){
		perror("fork");
		exit(0);
	}else if(pid > 0){
		print_id();
		exit(0);
	}else{
		sleep(2);
		setsid();
		print_id();
		int fd = open("/dev/tty12",O_RDWR);
		if(fd <0){
			perror("open");
			exit(1);
		}
		char buf[] = "hello";
		int nw = write(fd,buf,sizeof(buf));
		if(nw < 0){
			perror("write");
			exit(1);
		}
	}	
}
void 
print_id()
{
	int pgrp = getpgrp();
	int pid = getpid();
	int ppid = getppid();
	printf("pgrp:%d ,pid:%d ,ppid:%d\n",pgrp,pid,ppid);	
}
