
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <assert.h>
#include "ipc_ftp.h"
int
main( int argc,char *argv[])
{
	assert(argc == 2);
	int fd[2];
	socketpair(AF_UNIX,SOCK_STREAM,0,fd);
	int pid = fork();
	if(pid < 0){
		perror("fork");
		exit(1);
	}
	if(pid == 0){
		close(fd[0]);
		do_server(fd[1],fd[1]);
		exit(0);
	}
	close(fd[1]);
	do_client(fd[0],fd[0],argv[1]);
	waitpid(pid,NULL,0);
	exit(0);
}
