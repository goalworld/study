#include <stdio.h>
#include <stdlib.h>

typedef struct test{
	int a;
	int b;
	int c;
}test_t;
static int add(int a,int b);
static test_t test_struct(int a,int b,int c);
int 
main(int argc,char *argv[])
{
	printf("%d",add(1,2));	
	test_t tt =	test_struct(1,2,3);
}
static int 
add(int a,int b)
{
	__asm__ __volatile__(
		"addl %edi , %esi \n\t"
		"movl %esi , %eax \n\t"
	);
}

static test_t 
test_struct(int a,int b,int c){
	test_t tt = {.a=a,.b=b,.c=c};
	return tt;
}
