#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 6


int find_minkey(int key[], bool set[])
{
    int min_val = INT_MAX, index;

    for (int v = 0; v < V; v++)
    {
        if (set[v] == false && key[v] < min_val)
        {
            min_val = key[v];
            index = v;
        }
    }

    return index;
}



void prim_algo(int graph[V][V])
{
   
    int parent[V];
    
    int key[V];
  
    bool set[V];

    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        set[i] = false;

    }
     

  
    key[0] = 0;
    parent[0] = -1; 

   
    for (int count = 0; count < V - 1; count++) {
     
        int u = find_minkey(key, set);

    
        set[u] = true;

        for (int v = 0; v < V; v++)
        {

            if (graph[u][v] && set[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
    {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
}


int main()
{
    int graph[V][V] = { { 0, 3, 0, 0, 6, 5 },
                        { 3, 0, 1, 0, 0, 4 },
                        { 0, 1, 0, 6, 0, 4 },
                        { 0, 0, 6, 0, 8, 5 },
                        { 6, 0, 0, 8, 0, 2 },
                        { 5, 4, 4, 5, 2, 0 } };
    prim_algo(graph);

    return 0;
}