#include <iostream>
#include <map>
using namespace std;

void selection_sort(int a[8], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = a[i];
        int j = i + 1;
        int index = i;
        while (j < n)
        {
            if (a[j] <= min)
            {
                min = a[j];
                index = j;
            }
            j++;
        }
        swap(a[index], a[i]);
    }
}

int main()
{
    int a[8] = {432, 8, 530, 90, 88, 231, 11, 45};
    selection_sort(a, 8);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}