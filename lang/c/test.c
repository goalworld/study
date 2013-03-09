#include <stdio.h>
struct X{
	int a;
	char c;
	int b;
};
struct Y{
	int a;
	char c;
	int b;
	char d;
};
static int sa;
int sb;
int
main()
{
	do_something();
	printf("static %d %d\n",sa,sb);
    printf("%zu  %zu \n",sizeof(struct X),sizeof(struct Y));
    int a[5];
    printf("%x\n", a);
    printf("%x\n", a+1);
    printf("%x\n", &a);
    printf("%x\n", &a+1);	
    return 0;
}
