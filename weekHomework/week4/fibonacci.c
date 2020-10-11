#include<stdio.h>

int func(int a)
{
	printf("variable position%p\n",&a);
	printf("function position%p\n",(void*)func);
	if(a==0)
	{
		return 0;
	}
	else if(a==1)
	{
		return 1;
	}
	else
	{
		return (func(a-1)+func(a-2));
	}
}
int main()
{
	printf("%d",func(10));
	return 0;
}
