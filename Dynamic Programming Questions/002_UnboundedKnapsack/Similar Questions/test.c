#include<stdio.h>
#include<unistd.h>

int main()
{
    fork();
        printf("forked\n");
        return 0;
}