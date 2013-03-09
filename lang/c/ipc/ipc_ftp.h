#ifndef _IPC_FTP_H_
#define _IPC_FTP_H_

void do_server(int rfd,int wfd);
void do_client(int rfd,int wfd,const char *buf);

#endif
