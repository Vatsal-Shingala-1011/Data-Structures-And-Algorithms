#include <stdio.h>

int arry_sorted(int *arr[],int n)
{
    if(n==1)
    {
        return 1;
    }
    int restarray=arr_sorted(arr+1,n-1);
    return (restarray && arr[0]<arr[1]);

}

int main()
{

    
    return 0;
}