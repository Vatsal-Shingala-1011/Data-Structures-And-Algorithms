#include <stdio.h> //self
int selection(int *a, int n)
{
    int key;
    for (int i = 0; i < n - 1; i++)
    {
        int min =0;
        int j = i + 1;
        key =a[i];
        for(int p=i;p<n-1;p++)
        {
            if(a[j]<key)
            {
                min=j;
                key=a[j];
            }
            j++;
        }
        a[min]=a[i];
        a[i]=key;
        
    }
    return 0;
}
int main()
{
    int a[5] = {8, 0, 7, 1, 3};
    selection(a, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", a[i]);
    }
    return 0;
}