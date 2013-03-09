#include <sys/ipc.h>
#include <stdio.h>
#include <stdlib.h>

int
main()
{
	int i;
	int msgfd;
	for(i=0; i<10; i++){
		msgfd = msgget(IPC_PRIVATE,IPC_CREAT);
		printf("msgfd = %d\n",msgfd);
		msgctl(msgfd,IPC_RMID,NULL);
	}
}
