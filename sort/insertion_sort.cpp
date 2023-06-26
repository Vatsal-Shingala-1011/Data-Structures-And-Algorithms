#include<iostream> //self
#include<map>
using namespace std;

void insertion_sort(int a[8],int n){
    for (int i=1;i<n;i++)
    {
        int key=a[i];
        int j=i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

int main()
{
    int a[8] = {432, 8, 530, 90, 88, 231, 11, 45};
    insertion_sort(a, 8);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}