#include <stdio.h>
int bubble(int *a,int n)
{
    int temp;
    for(int i=0;i<n-1;i++)
    {
    for(int i=0;i<n-1;i++)
    {
     if(a[i]>a[i+1])
     {
        temp=a[i];
        a[i]=a[i+1];
        a[i+1]=temp;
     }   
    }
    }
    return 0;
}
int main()
{
    int a[6]={7,11,9,2,17,4};
    bubble(a,6);
    for(int i=0;i<6;i++)
    {
     printf("%d\n",a[i]);
    }
    return 0;
}