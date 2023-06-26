#include <stdio.h>
void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void shell_sort(int *a, int n) // arguments are array, size
{
    int gap = n / 2;
    while (gap >= 1)
    {
        for (int j = gap; j < n; j++)
        {
            for (int i = j - gap; i >= 0; i = i - gap)
            {
                if (a[i+gap] < a[i])
                {
                    swap(&a[i], &a[i + gap]);     //when elemrnt is less then -gap element
                }
                else{
                    break;  //when element is greater than -gap element
                }
            }
        }
        gap = gap / 2;
    }
}
int main()
{
    int a[8] = {432, 8, 530, 90, 88, 231, 11, 45};
    shell_sort(a, 8);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}