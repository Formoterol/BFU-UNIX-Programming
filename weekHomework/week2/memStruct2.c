#include<stdio.h>
struct a
{
    char y;
    int x;
}EX;
int main()
{
    printf("%x\n",&EX.x);
    printf("%x\n",&EX.y);
    printf("%d",sizeof(EX));
    return 0;
}
