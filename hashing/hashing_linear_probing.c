#include <stdio.h>
#define table_size 10
int a[table_size] = {0};

void insert(int key)
{
    int i = key % table_size;

    if (a[i] == 0)
    {
        a[i] = key;
    }
    else
    {
        i = (i + 1) % table_size;
        while (1)
        {
            if (a[i] == 0)
            {
                a[i ] = key;
                break;
            }
            i = (i + 1) % table_size;
        }
    }
}

void find(int key)
{
    int i = key % table_size;
    int count = 0;
    for (int j = i; count < table_size; j = (j + 1) % table_size, count++)
    {
        if (a[j] == key)
        {
            printf("%d is at index %d\n", key, j);
            return;
        }
    }
    printf("%d is not found\n", key);
}

void print()
{
    for (int i = 0; i < table_size; i++)
    {
        if (a[i] != 0)
        {
            printf("%d-->%d  ", i,a[i]);
        }
    }
    printf("\n");
}

int main()
{
    insert(43);
    insert(135);
    insert(72);
    insert(23);
    insert(99);
    insert(19);
    insert(82);
    print();
    find(43);
    find(99);
    find(999);
    find(19);

    return 0;
}