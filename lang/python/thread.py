import thread
import time
def work ( arg1,arg2 ) :
	print arg1,arg2
def main():
	for i in range(10):
		thread.start_new_thread(work,(1,i));
	time.sleep(1000);

if __name__ == '__main__' :
	main()