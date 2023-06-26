#include<iostream> //self
#include<map>
using namespace std;

int partition_index(int a[8],int low,int high){
    int pivot=a[low];
    int i=low+1,j=high;
    while(i<j){
        while(a[i]<=pivot)
        {i++;}
        while(a[j]>pivot)
        {j--;}
        if(i<j){
        swap(a[i],a[j]);
        }
    }
    swap(a[j],a[low]);
    return j;
}
void quick_sort(int a[8],int low,int high){
    if(low<high){
    int index=partition_index(a,low,high);
    quick_sort(a,low,index-1); //left
    quick_sort(a,index+1,high); //right
    }
}


int main()
{
    int a[8] = {432, 8, 530, 90, 88, 231, 11, 45};
    quick_sort(a, 0,7);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}