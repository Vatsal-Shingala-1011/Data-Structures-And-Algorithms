#include <stdio.h>
#define table_size 11
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
        int h2 = 8 - (key % 8);
        int x = 1;
        i = (i + (x * h2)) % table_size;
        while (1)
        {
            // printf("     *%d*   ", i);
            if (a[i] == 0)
            {
                a[i] = key;
                break;
            }
            i = (i + (x * h2)) % table_size;
        }
    }
}

void find(int key)
{
    int i = key % table_size;
    int count = 0;
    int h2 = 8 - (key % 8);
    int x = 1;
    i = (i + (x * h2)) % table_size;
    for (int j = i; count < table_size * table_size; j = (i + (x * h2)) % table_size, count++,x++)
    {
        // printf("    *%d*    ",j);
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
            printf("%d-->%d  ", i, a[i]);
        }
    }
    printf("\n");
}

int main()
{
    insert(20);
    insert(34);
    insert(45);
    insert(70);
    insert(56);
    print();
    find(20);
    find(34);
    find(45);
    find(19);

    return 0;
}