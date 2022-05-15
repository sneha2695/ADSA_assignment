#include <iostream>
using namespace std;
#include <limits.h>

// Number of vertices in the graph
#define V 8


int find_min_distance(int dist[], bool visited[])
{

    // Initialize min value
    int indx_min;
    int min_dist = INT_MAX;

    for (int v = 0; v < V; v++)
        if (visited[v] == false && dist[v] <= min_dist)
            min_dist = dist[v], indx_min = v;

    return indx_min;
}


void algo_dijkstra(int graph[V][V], int src)
{
    int dist[V]; 

    bool visited[V]; 

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, visited[i] = false;

    dist[src] = 0;

   
    for (int count = 0; count < V - 1; count++) {
       
        int u = find_min_distance(dist, visited);

        visited[u] = true;

        for (int v = 0; v < V; v++)

            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) //Update step
                dist[v] = dist[u] + graph[u][v];
    }

   
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
    cout << i << " \t\t" << dist[i] << endl;
    
}

int main()
{
    int src = 0;
    
    int graph[V][V] = { { 0, 1, 0, 0, 4, 8, 0, 0},
                        { 0, 0, 2, 0, 0, 6, 6, 0},
                        { 0, 0, 0, 1, 0, 0, 2, 0},
                        { 0, 0, 0, 0, 0, 0, 1, 4 },
                        { 0, 0, 0, 0, 0, 5, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 1, 0, 1 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 } };

    algo_dijkstra(graph, src);
	
	/*cout<<"Enter number of vertices"<<endl;
	cin>>num_vertex;
	
	cout<<"Enter matrix:"<<endl;
	
	for(int i;i<num_vertex;i++)
		cin>>graph_input[i][i];
	
	algo_dijkstra(graph_input, src);*/

    return 0;
}
