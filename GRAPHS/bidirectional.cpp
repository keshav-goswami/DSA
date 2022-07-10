#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+1;
vector<int> gf[N];
vector<int> s_visited[N];
vector<int> g_visited[N];
// Method for Breadth First Search

void BFS(list<int> *queue, bool *visited,int *parent)
{
	int current = queue->front();
	queue->pop_front();
	list<int>::iterator i;
	for (i = adj[current].begin();i != adj[current].end();i++)
	{
		if (!visited[*i])
		{
			parent[*i] = current;
			visited[*i] = true;
			queue->push_back(*i);
		}
	}
};

// check for intersecting vertex
int isIntersecting(bool *s_visited, bool *t_visited)
{
	int intersectNode = -1;
	for(int i=0;i<V;i++)
	{
		if(s_visited[i] && t_visited[i])
			return i;
	}
	return -1;
};

// Print the path from source to target
void Graph::printPath(int *s_parent, int *t_parent,
				int s, int t, int intersectNode)
{
	vector<int> path;
	path.push_back(intersectNode);
	int i = intersectNode;
	while (i != s)
	{
		path.push_back(s_parent[i]);
		i = s_parent[i];
	}
	reverse(path.begin(), path.end());
	i = intersectNode;
	while(i != t)
	{
		path.push_back(t_parent[i]);
		i = t_parent[i];
	}

	vector<int>::iterator it;
	cout<<"*****Path*****\n";
	for(it = path.begin();it != path.end();it++)
		cout<<*it<<" ";
	cout<<"\n";
};

int biDirSearch(int s, int t)
{
	bool s_visited[V], t_visited[V];
	int s_parent[V], t_parent[V];
	list<int> s_queue, t_queue;

	int intersectNode = -1;
	for(int i=0; i<V; i++)
	{
		s_visited[i] = false;
		t_visited[i] = false;
	}

	s_queue.push_back(s);
	s_visited[s] = true;

	s_parent[s]=-1;

	t_queue.push_back(t);
	t_visited[t] = true;

	t_parent[t] = -1;

	while (!s_queue.empty() && !t_queue.empty())
	{
		BFS(&s_queue, s_visited, s_parent);
		BFS(&t_queue, t_visited, t_parent);
		intersectNode = isIntersecting(s_visited, t_visited);
		if(intersectNode != -1)
		{
			cout << "Path exist between " << s << " and "
				<< t << "\n";
			cout << "Intersection at: " << intersectNode << "\n";
			printPath(s_parent, t_parent, s, t, intersectNode);
			exit(0);
		}
	}
	return -1;
}

// Driver code
int main()
{
	int n=15;
	int s=0;

	int t=14;

	Graph g(n);

	if (g.biDirSearch(s, t) == -1)
		cout << "Path don't exist between "
			<< s << " and " << t << "\n";

	return 0;
}
// input 
// 0 4
// 1 4
// 2 5
// 3 5
// 4 6
// 5 6
// 6 7
// 7 8
// 8 9
// 8 10
// 9 11
// 9 12
// 10 13 
// 10 14