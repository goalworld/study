#include <sys/shm.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define SHM_SIZE 10000
#define SHM_MODE 0600
void  workss(int id);
void * p;
int main()
{
	int shmid = shmget(IPC_PRIVATE,SHM_SIZE,SHM_MODE);
	printf("shmid%d\n",shmid);
	p = shmat(shmid,0,0);
	int pid = fork();
	if(pid < 0){
		perror("fork");
		exit(1);
	}
	if(pid == 0){
		workss(shmid);
		exit(0);
	}

	workss(shmid);
	waitpid(pid,NULL,0);
	printf("%d \n",*(int *)p);	
}
void  
workss(int id)
{
	//void * p = shmat(id,0,0);
	int i=0;
	printf("%d\n",i);
	for(i=0;i<10000;i++)
		*(int *)p+=1;
}
