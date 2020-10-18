#include<stdio.h>
https://blog.csdn.net/flowing_wind/article/details/81240910
int main(int argc,char **argv[],char **envp[])
{
	int MB = 0;  
    while(malloc(1 << 20))  
	{  
        MB++;  
    }  
    printf("The max Heap space is  %d MB total\n", MB);
	return 0; 
}
