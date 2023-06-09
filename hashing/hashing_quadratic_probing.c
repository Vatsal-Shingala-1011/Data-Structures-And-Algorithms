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
        int x = 1;
        i = (i + (x * x)) % table_size;
        x++;
        while (1)
        {
            if (a[i] == 0)
            {
                a[i] = key;
                break;
            }
            i = (i + (x * x)) % table_size;
            x++;
        }
    }
}

void find(int key)
{
    int i = key % table_size;
    int count = 0;
    int x = 1;
    for (int j = i; count < table_size * table_size; j = (j + (x * x)) % table_size, x++, count++)
    {
        if (a[j] == key)
        {
            printf("%d is at index %i\n", key, j);
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
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

int main()
{
    insert(42);
    insert(16);
    insert(91);
    insert(33);
    insert(18);
    insert(27);
    insert(36);
    // insert(62);  //// no find slot for 62
    print();
    find(42);
    find(91);
    find(33);
    find(91);
    find(99);
    

    return 0;
}