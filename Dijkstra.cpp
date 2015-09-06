#include<iostream>
#include<list>
using namespace std;

#define MAXN 100
#define INFINITY 65535

class Graph
{
	int V;
	int weight[MAXN][MAXN];

public:
	Graph(int V);
	void addEdge(int v, int w, int weight);
	void Dijkstra(int s);
};

Graph::Graph(int V)
{
	this->V = V;

	for(int i=0; i<V; i++)
	{
		for(int j=0; j<V; j++)
		{
			if(i != j)
				this->weight[i][j] = INFINITY;
			else
				this->weight[i][j] = 0;
		}
	}
}

void Graph::addEdge(int v, int w, int weight)
{
	this->weight[v][w] = weight;
	this->weight[w][v] = weight;
}

void Graph::Dijkstra(int s)
{
	bool *visited = new bool[V];
	int *dist = new int[V];
	int cur;

	for (int i=0; i<V; ++i)
	{
		dist[i] = weight[s][i] < INFINITY ? weight[s][i] : INFINITY;
	}

	cur = s;
	visited[cur] = true;

	for(int i=0; i<V-1; i++)
	{
		int min = INFINITY;
		for(int j=0; j<V; j++)
		{
			if(!visited[j] && dist[j] < min)
			{
				min = weight[cur][j];
				cur = j;
			}
		}

		visited[cur] = true;

		for(int k=0; k<V; k++)
		{
			if(dist[cur] + weight[cur][k] < dist[k])
				dist[k] = dist[cur] + weight[cur][k];
		}
	}

	for(int i=0; i<V; i++)
	{
		cout<<dist[i]<<" ";
	}
	cout<<endl;

}

int main()
{
	Graph graph(4);
	graph.addEdge(0, 1, 1);
    graph.addEdge(1, 3, 2);
    graph.addEdge(2, 0, 1);
    graph.addEdge(0, 3, 1);

    graph.Dijkstra(0);

    return 0;
}
