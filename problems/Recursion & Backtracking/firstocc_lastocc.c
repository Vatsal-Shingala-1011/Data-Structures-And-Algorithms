#include <stdio.h>

int firstocc(int arr[],int n,int i,int key)
{
    if(i==n)
    {
        return -1;
    }
    if(arr[i]==key)
    {
        return i;
    }
    return firstocc(arr,n,i+1,key);
}   
//both function are  working well
int lastacc(int arr[],int n,int i,int key)
{
    if(i==n)
    {
        return -1;
    }
    int restarray=lastacc(arr,n,i+1,key);
    if(restarray==-1)
    {
        if(arr[i]==key)
        {
            return i;
        }
        else 
        {
            return -1;
        }
    }
    return restarray;
}
// int lastacc(int arr[],int n,int i,int key)
// {
//     if(i==n)
//     {
//         return -1;
//     }
//     int restarray=lastacc(arr,n,i+1,key);
//     if(restarray!=-1)
//     {
//         return restarray;
//     }

//     if(arr[i]==key)
//         {
//             return i;
//         }
//       return -1;
// }

int main()
{
    int arr[5];

    for(int i=0;i<5;i++)
    {
    scanf("%d",&arr[i]);
    }
    printf("%d",lastacc(arr,5,0,4));
    return 0;
}