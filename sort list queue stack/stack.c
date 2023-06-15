#include <stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int* arr;
};
int isEmpty(struct stack *ptr)
{
    if((*ptr).top==-1)   //or ptr->top
    {
        return 1;
    }
    return 0;
}
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack* ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int main()
{
    struct stack s;
    s.size=5;
    s.top=-1;
    s.arr=(int *) malloc(sizeof(int)*s.size);
    push(&s,4);
    push(&s,4);
    int ppp=pop(&s);
    printf("%d",ppp);
    return 0;
}