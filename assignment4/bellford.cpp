#include <limits.h>
#include <iostream>
using namespace std;

struct Edge {
    int src;
    int dest;
    int weight;
}; //Node for Graph

const int max_vertices = 100;

struct Graph {
  
    int V, E;

    struct Edge* edge;
}; 

struct Graph* graph_create(int V, int E) //Creating graph
{
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}


void print(int dist[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}


void algo_bellmanFord(struct Graph* graph, int src,int V, int E)
{
    int dist[max_vertices];


    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX; //initialize to very high distance 
    dist[src] = 0;

   
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX
                && dist[u] + weight < dist[v]) //Update check
                dist[v] = dist[u] + weight;
        }
    }

  
    for (int i = 0; i < E; i++) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX
            && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle");
            return; // If negative cycle is present , just return
                    
        }
    }

    print(dist, V);

    return;
}


int main()
{
    int V, E;

    printf("Enter the number of the vertices");
    cin >> V;

    printf("Enter the number of the edges");
    cin >> E;
  
    struct Graph* graph = graph_create(V, E); //Initialize the number of vertices/edges
    int source = 0;

    for (int i = 0; i < E; i++)
    {
        printf("Enter the source");
        cin >> graph->edge[i].src;

        printf("Enter the dest");
        cin >> graph->edge[i].dest;

        printf("Enter the weight");
        cin >> graph->edge[i].weight;
    }

    algo_bellmanFord(graph, source,V,E); //sending source as vertex 0

    return 0;
}