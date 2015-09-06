#include<iostream>
#include<list>
using namespace std;

class Graph
{
	int V;
	list<int> *adj;
	void DFS_VISIT(int v, bool visited[]);

public:
	Graph(int V);
	void addEdge(int v, int w);
	void DFS();
	
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::DFS()
{	
	bool *visited = new bool[V];

	for(int i=0; i<V; i++)
		visited[i] = false;

	for(int i = 0; i < V; ++i)
	{
		if(!visited[i])
			DFS_VISIT(i, visited);
	}

	cout<<endl;
}

void Graph::DFS_VISIT(int v, bool visited[])
{
	visited[v] = true;

	cout<<v<<" ";

	list<int>::iterator i;

	for(i = adj[v].begin(); i != adj[v].end(); ++i)
	{
		if(!visited[*i])
			DFS_VISIT(*i, visited);
	}
}


int main()
{
	Graph graph(4);
	graph.addEdge(0, 1);
	graph.addEdge(0, 1);
    graph.addEdge(1, 3);
    graph.addEdge(2, 0);
    graph.addEdge(3, 3);

    graph.DFS();

    return 0;
}
