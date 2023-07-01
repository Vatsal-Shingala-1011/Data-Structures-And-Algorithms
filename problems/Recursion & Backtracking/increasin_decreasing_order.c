#include <stdio.h>

int increasing(int n)
{
    if(n==0)
    {
        return;
    }
    printf("%d\n",n);
    increasing(n-1);
}

int decreasing(int n)
{
    if(n==0)
    {
        return;
    }
    decreasing(n-1);
    printf("%d\n",n);
}
int main()
{
    increasing(5);
    decreasing(5);
    return 0;
}