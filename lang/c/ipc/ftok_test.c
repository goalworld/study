#include <sys/stat.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <stdlib.h>
int
main(int argc,char *argv[])
{
	struct stat st;
	if(argc != 2){
		puts("arg err");
		exit(1);
	}
	if ( stat(argv[1],&st) < 0){
		perror("fstat");
		exit(1);
	}
	printf("st_dev: %lx,st_ino:%lx,key:%x\n",
		(u_long)st.st_dev,(u_long)st.st_ino,ftok(argv[1],0x57));
	return 0;
}
