#include <stdio.h> // can use queue or stack or array
#include <stdlib.h>
#define V 6
struct queue 
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("This Queue is full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("This Queue is empty\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int graph[V][V] = {{0, 0, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 0},
                   {0, 0, 0, 0, 1, 1},
                   {0, 0, 0, 0, 1, 1},
                   {0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0}};
// int graph[V][V] = {{0, 0, 0, 0, 0, 0},
//                    {0, 0, 0, 0, 0, 0},
//                    {0, 0, 0, 1, 0, 0},
//                    {0, 1, 0, 0, 0, 0},
//                    {1, 0, 0, 0, 0, 0},
//                    {1, 0, 1, 0, 0, 0}};

void topological_sort()
{
    struct queue q;
    q.r = q.f = 0;
    q.size = 400;
    q.arr = (int *)malloc(q.size * sizeof(int));
    int indegree[V] = {0}; // store indegree of each vertix
    int toposort[V];

    for (int i = 0; i < V; i++) // set indegee of each vertix
    {
        for (int j = 0; j < V; j++)
        {
            if (graph[j][i] == 1)
            {
                indegree[i]++;
            }
        }
    }
    for (int i = 0; i < V; i++)  //enqueue all node with indegree zero
        {
            if (indegree[i] == 0)
            {
                enqueue(&q, i);
            }
        }
    
    // enqueue(&q,1);// comment for loop and uncomment these two line to start with 1(B)
    // enqueue(&q,0);//

    while (!isEmpty(&q))
    {
        int poped=dequeue(&q);//remove from queue and decrease indegee of connected node with removed node by 1
        printf("%d ",poped);
        for (int i = 0; i < V; i++)
        {
            if(graph[poped][i]==1)
            {
                indegree[i]--;
                if(indegree[i]==0)   //if indegree is zero then add that node into queue
                {
                    enqueue(&q,i);
                }
            }
        }
        

    }
}

int main()
{
    topological_sort();
    return 0;
}
