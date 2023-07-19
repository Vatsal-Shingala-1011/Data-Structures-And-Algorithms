#include <stdio.h> //use queue
#include <stdlib.h>
#define V 5

int graph[V][V] = {{0, 1, 1, 0, 0},
                   {1, 0, 1, 1, 0},
                   {1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1},
                   {0, 0, 0, 1, 0}};

void detect_cycle_in_directed_graph()
{
    struct stack s;
    s.size = 100;
    s.top = -1;
    s.arr = (int *)malloc(sizeof(int) * s.size);

    int key[V]; // key=-1 unvisited, 1 for visited &in queue ,1 visited and pop from queue
    for (int i = 0; i < V; i++)
    {
        key[i] = -1;
    }
    int parent[V] = {0}; //store parent of node
    int i = 0;//let first node take as 0
    key[i] = 1; //**************************diferent from directed cycle ************************************
    parent[i] = -1;
    push(&s, i);
    int bre = 0; //for cycle found then break =1
    while (!isEmpty(&s))
    {
        int count = 0;
        for (int j = 0; j < V; j++)
        {
            if (graph[i][j] == 1 && key[j] == -1) // if connected node is -1
            {
                key[j] = 0; // visited
                parent[j] = i;
                push(&s, j);
                count++;
            }else if (graph[i][j] == 1 && key[j] == 0)
            {
                push(&s, j);
                printf("loop found\n");
                count++;
                bre = 1;
                break;
            }
        }
        if (bre == 1)  //if cycle found then break;
        {
            break;
        }
        if (count == 0) //if there is no node connected to j with -1 key 
        {
            pop(&s);
            key[i] = 1;
        }
        i = s.arr[s.top]; // top element in queue
    }
    int loop=-1;
    int x = pop(&s);
    printf("%d ", x);
    while (loop != x)
    {
        loop = pop(&s);
        printf("%d ", loop);
    }
}

int main()
{
    detect_cycle_in_directed_graph();
    return 0;
}
