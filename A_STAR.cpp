#include<iostream>
using namespace std;

#define LENGTH 7
#define HIGH 5
#define MAX 65535

class Graph
{
	// int matrix[LENGTH][HIGH];
	int V = LENGTH * HIGH;
	list<int> *adj;

	//f(n) = g(n) + h(n
	int h(int v);
	int g(int v);

public:
	Graph(int start, int end);
	void A_STAR(int start, int end);
};

Graph::Graph()
{
	adj = new list<int>[V];

	for (int i = 0; i < V; ++i)
	{
		adj[i].push_back(i - 1);
		adj[i].push_back(i - 1);
		adj[i].push_back(i + LENGTH);
		adj[i].push_back(i - LENGTH);
	}

	//remove location in the area of block
}

void Graph::A_STAR(int start, int end)
{
	list<int> open;
	list<int> close;

	int father = new int[V];
	int cur = start;

	while(cur != end)
	{
		int minf = MAX;
		int tmpv  = 0;

		for(list<int>::iterator i = adj[cur].begin(); i != adj[cur].end(); ++i)
		{
			if(f(*i) < minf)
			{
				minf = f(*i);
				tmpv = *i;
			}
		}

		open.remove(cur);
		close.remove(cur);

		cur = tmpv;
	}
}