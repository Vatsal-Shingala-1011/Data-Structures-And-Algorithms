#include <stdio.h>
int visited[7] = {0, 0, 0, 0, 0, 0, 0};
int a[7][7] = {
    //---->j
    {0, 1, 1, 1, 0, 0, 0}, // |
    {1, 0, 1, 0, 0, 0, 0}, // |
    {1, 1, 0, 1, 1, 0, 0}, // |
    {1, 0, 1, 0, 1, 0, 0}, // i
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}};

void DFS(int i)
{
    visited[i]=1;
    printf("%d ",i);
    for (int j = 0; j < 7; j++)
    {
        if(a[i][j]==1 && visited[j]==0)
        {
            visited[j]=1;
            DFS(j);
        }
    }
}

int main()
{
    DFS(0);
    return 0;
}
