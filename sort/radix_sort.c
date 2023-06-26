#include <stdio.h>
int max_digit(int *a, int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    int b = max;
    int count = 0;
    while (b != 0)
    {
        count++;
        b = b / 10;
    }
    return count;
}

void radix_sort(int *a, int n) // arguments are array, size
{
    int pass = max_digit(a, n) + 1;
    int pos = 1;
    int b[8];
    while (pass--)
    {
        int count[10] = {0};
        for (int i = 0; i < n; i++)
        {
            count[(a[i] / pos) % 10]++;
        }
        for (int i = 1; i < 10; i++)
        {
            count[i] = count[i] + count[i - 1];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            b[count[(a[i] / pos) % 10] - 1] = a[i];
            count[(a[i] / pos) % 10]--;
        }
        for (int i = 0; i < n; i++)
        {
            a[i] = b[i];
        }
        pos = pos * 10;
    }
}
int main()
{
    int a[8] = {432, 8, 530, 90, 88, 231, 11, 45};
    radix_sort(a, 8);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}