#_*_ coding:utf-8 _*_ 
import sys
import module_test as test
#import vvku.test
class foo(object):
	"foo"
	pass
def main():
	t = test.test_class(1);
	print dir(t)
	del t;
	test._init()
	print test.add(1,2) 
	print("hello world")
	a = {"key1":1,"23":2}
	for key in a.keys():
		print'key=%s,value=%d'%(key,a[key])
	arr = [1,2,3,4,5,6]
	for i in xrange(len(arr)):#range
		str = '%d,%s'%(i,arr[i])
		print str
	files = open("1.txt","w+")
	for i in xrange(2):
		files.write("111hello\n")
	print files.tell()
	files.seek(0,0)
	#print files.read()
	for line in files:
		print(line)
	files.close()
	print "imput>"
	str = sys.stdin.readline();
	sys.stdout.write(str);
if __name__ == '__main__':
	main(); 	