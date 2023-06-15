#include <stdio.h>
#include<stdlib.h>
int main()
{
    struct q
    {
        int size;
        int f;
        int r;
        int *arr;
    };
    int a[7][7]={
        {0,1,1,1,0,0,0},
        {1,0,0,1,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    int i=0;
    enque(&q,i);
    int visited[7]={0,0,0,0,0,0,0};
    while(q is not empty)
    {
        visited[i]=1;
        dequeue(&q,i);

    }
       
    return 0;
}