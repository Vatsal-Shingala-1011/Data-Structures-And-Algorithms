#include <stdio.h> //100% self //not optimal solution
#include <limits.h>
#define V 4 // vertexs
#define E 5 // edges
/* Let us create following weighted graph
                   10
              0--------1
              |  \     |
             6|   5\   |15
              |      \ |
              2--------3
                  4       */

// Here 5 is the number of edges, can be asked from the user when making the graph through user input 3 represents the no of index positions for storing u --> v(adjacent vertices) and its cost/distance;
int edge[5][3] = {{0, 1, 10}, // node,node,weight
                  {0, 2, 6},
                  {0, 3, 5},
                  {1, 3, 15},
                  {2, 3, 4}};
// int graph[V][V] = {{0, 10, 6, 5},   //same graph with different representation
//                    {10, 0, 0, 15},
//                    {6, 0, 0, 4},
//                    {5, 15, 4, 0}};
void kruskalalgo()
{
    int group = 1;        // group number
    int key[V] = {0};     // key of node (0 for no group for 1 that node is in group number 1 for 2 is in group2)
    int mstedge[E] = {0}; // edge (if 0 then not check yet for MST,if -1 then checked but it is forming cycle so not include in MST)
    int index;            // index of min weight edge which is not in MST

    for (int v = 0; v < E; v++) // edge times
    {
        int min = INT_MAX;
        for (int i = 0; i < E; i++) // for finding index of min weight edge which is not in MST
        {
            if (mstedge[i] == 0 && edge[i][2] < min)
            {
                min = edge[i][2];
                index = i;
            }
        }
// printf("%d   %d",min,index);
        mstedge[index] = 1; // include min edge to MST

        if (key[edge[index][0]] == 0 && key[edge[index][1]] == 0) // if both nodes are not in the group
        {
            key[edge[index][0]] = group;
            key[edge[index][1]] = group; // then give group number to both
            group++;                     // group occupied so new group index
        }
        else if ((key[edge[index][0]] != 0 && key[edge[index][1]] == 0)) // if first one is in the any group
        {
            key[edge[index][1]] = key[edge[index][0]];
        }
        else if ((key[edge[index][0]] == 0 && key[edge[index][1]] != 0)) // if second one is in the any group
        {
            key[edge[index][0]] = key[edge[index][1]];
        }
        else // both are in group
        {
            if ((key[edge[index][0]] != key[edge[index][1]])) // different group
            {
                for (int k = 0; k < V; k++)
                {
                    if (key[k] != key[edge[index][1]]) //combine two group to one single group
                    {
                        key[k] = key[edge[index][0]];
                    }
                }
            }
            if ((key[edge[index][0]] == key[edge[index][1]])) // both are in same group
            {
                mstedge[index] = -1; // remove take this weight

            }
        }
    }
    // for (int i = 0; i < E; i++)
    // {

    //     printf(" *** %d ***\n\n", mstedge[i]);
    // }

    for (int i = 0; i < E; i++)
    {
        if (mstedge[i] != -1)
        {
            printf("%d-->%d    %d\n", edge[i][0], edge[i][1], edge[i][2]);
        }
    }
}

int main()
{
    kruskalalgo();
    return 0;
}
