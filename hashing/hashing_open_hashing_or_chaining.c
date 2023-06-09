#include <stdio.h>
#include <stdlib.h>
#define table_size 10
struct node
{
    int key;
    struct node *next;
};
struct node *head[table_size] = {NULL};

void insert(int key)
{
    int i = key % table_size;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->key = key;
    newnode->next = NULL;
    if (head[i] == NULL)
    {
        head[i] = newnode;
    }
    else
    {
        struct node *ptr;
        ptr = head[i];
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }
}

void find(int key)
{
    int i = key % table_size;
    struct node *ptr;
    ptr = head[i];
    if (head[i] == NULL)
    {
        printf("key is not found \n");
    }
    else if (head[i]->key == key)
    {
        printf("%d is at index %i \n", key, i);
    }
    else
    {
        ptr = head[i]->next;
        while (ptr != NULL)
        {
            if (ptr->key == key)
            {
                printf("%d is at index %i \n", key, i);
            }
            ptr = ptr->next;
        }
    }
}

void print()
{
    struct node *ptr;
    for (int i = 0; i < table_size; i++)
    {
        ptr = head[i];
        if (head[i] != NULL)
        {
            while (ptr != NULL)
            {
                printf("%d ", ptr->key);
                ptr = ptr->next;
            }
        }
    }
    printf("\n");
}

int main()
{
    insert(1);
    insert(11);
    insert(14);
    insert(31);
    insert(14);
    insert(17);
    insert(20);
    insert(78);
    print();
    find(11);
    find(17);
    find(31);

    return 0;
}