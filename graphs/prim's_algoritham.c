#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
// Number of vertices in the graph
#define V 5
int graph[V][V] = {{0, 2, 0, 6, 0}, //--->j
                   {2, 0, 3, 8, 5}, //|
                   {0, 3, 0, 0, 7}, //|i
                   {6, 8, 0, 0, 9},
                   {0, 5, 7, 9, 0}};

void primMST()
{
    int key[V];
    int parent[V];
    int a[V] = {0}; // node is in mst or not

    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
    }
    key[0] = 0;
    parent[0] = -1;
    int u; // u is min key amongs node in mst (a)

    for (int v = 0; v < V - 1; v++)   //doing V-1 times because for last element no need to check in non mst
    {

        int min = INT_MAX;
        for (int i = 0; i < V; i++) // select min key node
        {
            if (a[i] == 0 && key[i] < min) // is not in a and min key node then
            {
                u = i;
                min = key[i];
            }
        }

        a[u] = 1; // add min node in to mst (a)

        for (int i = 0; i < V; i++) // update value of connected node from u if corrunt weight is more than edge weight eith u
        {
            if (graph[u][i] && a[i] == 0 && graph[u][i] < key[i]) // node from not mst connected with u and value of curr is less then new
            {
                key[i] = graph[u][i];         // update value of weight
                parent[i]=u;                  //update parent if parent to node weight is small than previous parent to node weight  
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        printf("%d --> %d     %d  \n", i, parent[i], graph[i][parent[i]]);      //here weare not changing the graphs weight but we only print min weight value
    }
}

int main()
{
    primMST();
    return 0;
}
//second approach
//pseudocode for Prim’s Algorithm
// PrimMST(graph G)
//     for each vertex v in G:
//         v.distance = infinity
//     start = arbitrary vertex
//     start.distance = 0
//     priorityQueue = all vertices in G
//     while priorityQueue is not empty:
//         u = vertex with smallest distance in priorityQueue
//         remove u from priorityQueue
//         for each neighbor v of u:
//             if v is in priorityQueue and weight(u, v) < v.distance:
//                 v.distance = weight(u, v)
//                 v.parent = u
//     return MST

