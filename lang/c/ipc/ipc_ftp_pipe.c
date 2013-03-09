#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ipc_ftp.h"
int
main( int argc,char *argv[])
{
	assert(argc == 2);
	int ctlfd[2];
	int datafd[2];
	pipe(ctlfd);
	pipe(datafd);
	int pid = fork();
	if(pid < 0){
		perror("fork");
		exit(1);
	}
	if(pid == 0){
		close(ctlfd[1]);
		close(datafd[0]);
		do_server(ctlfd[0],datafd[1]);
		exit(0);
	}
	close(ctlfd[0]);
	close(datafd[1]);
	do_client(datafd[0],ctlfd[1],argv[1]);
	waitpid(pid,NULL,0);
	exit(0);
}
