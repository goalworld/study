all:./ipc_ftp_socketpair ./ipc_ftp_pipe
./ipc_ftp_pipe:ipc_ftp_pipe.c ipc_ftp.c
	gcc  $^ -o $@
./ipc_ftp_socketpair:ipc_ftp_socketpair.c ipc_ftp.c
	gcc  $^ -o $@
