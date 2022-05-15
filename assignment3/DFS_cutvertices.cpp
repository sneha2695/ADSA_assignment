#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;

#define num_of_vertices 1000

void addEdge_graph(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}


void dfs_search(vector<int> adj[], int u, bool visited[],
	int dis[], int low[], int& time, int parent,
	bool color[])
{
	int children = 0;

	visited[u] = true;

	dis[u] = low[u] = ++time;

	for (auto v : adj[u]) {
		
		if (!visited[v]) {
			children++;
			dfs_search(adj, v, visited, dis, low, time, u, color);

			low[u] = min(low[u], low[v]);

			if (parent != -1 && low[v] >= dis[u])
				color[u] = true;
		}

		else if (v != parent)
			low[u] = min(low[u], dis[v]);
	}

	if (parent == -1 && children > 1)
		color[u] = true;
}


int main()
{
	int e1,e2;
	vector<int> adj_list[num_of_vertices];
	int V;
	int num_edges;
	int dis[num_of_vertices] = { 0 };
	int low[num_of_vertices];
	bool visited[num_of_vertices] = { false };
	bool color[num_of_vertices] = { false };
	int time = 0, parent = -1;

	cout<<"The number of vertices"<<endl;
	cin>>V;
	
	cout<<"Enter number of edges:"<<endl;
	cin>>num_edges;
	
	for(int i=0;i<num_edges;i++)
	{
		cout<<"Enter edge1"<<endl;
		cin>>e1;
		
		cout<<"Enter edge2"<<endl;
		cin>>e2;
		
		addEdge_graph(adj_list, e1,e2);
	}

	for (int u = 0; u < V; u++)
	{
		if (!visited[u])
		{
			dfs_search(adj_list, u, visited, dis, low,
				time, parent, color);
		}
	}

    cout << "\nArticulation points in the graph \n";
	
	for (int u = 0; u < V; u++)
	{
		if (color[u] == true)
			cout << u << " ";
	}

	return 0;
}

