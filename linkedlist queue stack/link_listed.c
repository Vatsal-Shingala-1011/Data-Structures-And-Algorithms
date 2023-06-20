#include <stdio.h>
#include <stdlib.h>
//struct is struct is contain value of data and address of same type(data type) of node
struct Node
{
    int data;            //4 byte
    struct Node *next;   //4 byte (pointer in 32 bits compiler)
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    struct Node *head; //assign pointer of 8byte(int) in stack
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));    //head point memory location in heap
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    // Link first and second nodes
    head->data = 7;          //*(head).data =7;   
    head->next = second;
    // Link second and third nodes
    second->data = 11;
    second->next = third;
    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;
    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = NULL;
    linkedListTraversal(head);
    return 0;
}

//struct node s1;
//struct node *ptr;
//*(ptr).data = 10;
//ptr->data =10;




































































