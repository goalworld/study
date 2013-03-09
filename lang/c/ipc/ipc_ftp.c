#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <assert.h>
#include <string.h>
#include <fcntl.h>


void 
do_client(int rfd,int wfd,const char *path)
{
	int nw = write(wfd,path,(strlen(path)+1)*sizeof(char));
	if(nw < 0 && errno != EINTR)	return;
	char *buf[1025];
	for(;;){
		int nr = read(rfd,buf,1024);
		if(nr < 0 && errno == EINTR) continue;
		else if(nr > 0){
			buf[nr]='\0';
			printf("%s",buf);
		}else if(nr < 0){
			perror("read error");
			break;
		}else{
			break;
		}
	}
}
static int read_string(int fd,char *buf,size_t sz);
static int read_to_fd(const char *name,int fd);
 void
do_server(int rfd,int wfd)
{
	puts("read");
	char path[256];
	int nread;
	int nwrite;
	for(;;){
		int nr = read_string(rfd,path,255);		
		if(nr < 0){
			return ;
		}
		path[nr] = '\0';
		int ret = read_to_fd(path,wfd);
		if(ret <= 0){
			return;
		}
	}
}
static int 
read_to_fd(const char* path,int wfd){
	char *buf[1024];
	int nr;
	int nw;
	int fd = open(path,O_RDONLY);
	if(fd < 0){
		return -1;
	}
	for(;;){
			nr = read(fd,buf,1024);
			if(nr <0 && errno != EINTR)		return -1;
			if(nr == 0){
				return 0;
			}
			while (1){
			 	nw = write(wfd,buf,nr);
				if(nw < 0 && errno != EINTR) continue;
				else break;
			}
			if(nw < 0){
				return -1;
			}
			assert(nw == nr);
	}
}
static int 
read_string(int fd,char *path,size_t sz)
{
	if(!path || !sz){
		return -1;
	}
	char c;
	int allnr = 0;
	int nr;
	for(;;){
		nr = read(fd,&c,sizeof(char));
		printf("%c",c);
		fflush(stdout);
		if(nr < 0 && errno != EINTR || nr == 0){
			perror("read_string read");
			return nr;
		}
		if(c == '\0'){
			return allnr;
		}
		path[allnr++] = c;
		if(allnr == sz){
			return sz;
		}
	}
}
