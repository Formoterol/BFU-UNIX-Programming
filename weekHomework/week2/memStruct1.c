#include<stdio.h>
struct a
{
    int x;
    char y;
}EX;
int main()
{
    printf("%x\n",&EX.x);
    printf("%x\n",&EX.y);
    printf("%d",sizeof(EX));
    return 0;
}
