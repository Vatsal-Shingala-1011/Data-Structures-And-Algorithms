#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
// Number of vertices in the graph
#define V 4

// int graph[V][V] = {{0, 2, 0, 6, 0}, //--->j
//                    {2, 0, 3, 8, 5}, //|
//                    {0, 3, 0, 0, 7}, //|i
//                    {6, 8, 0, 0, 9},
//                    {0, 5, 7, 9, 0}};

int graph[V][V] = {{0, 3, 2, 0}, //--->j
                   {3, 0, 1, 5}, //|
                   {2, 1, 0, 4}, //|i
                   {0, 5, 4, 0}};

int primMST() {
  int v[V];       // is not included
  int a[V] = {0}; // is included
  for (int i = 0; i < V; i++) {
    v[i] = 1;
  }
  int parent[V];
  int i = 0; // let starts with 0
  v[i] = 0;  // remove from v
  a[i] = 1;  // added to as
  int key;
  parent[0] = -1; // let 0 is root node

  for (int k = 0; k < V - 1; k++) // only for count V-1
  {
    int minweight = INT_MAX;

    for (int anode = 0; anode < V; anode++) {
      if (a[anode] == 1) {
        for (int vnode = 0; vnode < V; vnode++) //   find min cost root
        {
          if (v[vnode] == 1 &&
              graph[anode][vnode] != 0) // ele in v and conected with i
          {
            if (graph[anode][vnode] < minweight) {
              minweight = graph[anode][vnode];
              key = vnode;
              parent[vnode] = anode;
            }
          }
        }
      }
    }

    v[key] = 0;
    a[key] = 1;
  }
  for (int i = 0; i < V; i++) {
    printf("%d --> %d       %d  \n", i, parent[i], graph[i][parent[i]]);  //here weare not changing the graphs weight but we only print min weight value
  }
}

int main() {
  /* Let us create the following graph
      2 3
  (0)--(1)--(2)
  | / \ |
  6| 8/ \5 |7
  | /     \ |
  (3)-------(4)
          9         */

  // Print the solution
  primMST();

  return 0;
}
