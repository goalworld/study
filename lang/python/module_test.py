def _init():
	print "module_test init"
def add(a,b):
	return a+b
def sub(a,b):
	return a-b
if __name__ == "module_test":
	_init();

class test_class(object):
	"""docstring for test_class"""
	a = 1
	def __init__(self, arg):
		print("__init__");
		super(test_class, self).__init__()
		self.arg = arg
	#def __new__(self,arg):
	#	print("__new__");
	def __del__(slef):
		print("__del__");
	def __test(self):
		print self.arg