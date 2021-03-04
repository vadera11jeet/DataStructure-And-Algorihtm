#include<bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, vector<int>> adj;
    int vertex;

    void topologicalSortUtil(int src, vector<bool> & visited, stack<int> & ans, int timer, vector<int> &time)
    {
        visited[src] = true;
        time[src] = timer+1;

        for(auto x : adj[src])
        {
            if(!visited[x])
                topologicalSortUtil(x, visited, ans, timer+1, time);
        }

        ans.push(src);
    }

public:

    Graph(int vertex)
    {
        this->vertex = vertex;
    }

    void addEdge(int w, int v)
    {
        adj[w].push_back(v);
    }

    void topologicalSort()
    {
        vector<bool>visited(vertex, false);
        stack<int> s;
        vector<int>timer(vertex + 3, 0);

        for(int i = 0; i < vertex; i++)
            if(!visited[i])
                topologicalSortUtil(i, visited, s, 0, timer);


        for(int i = 1; i<=vertex; i++)
            cout<<timer[i]<< "  ";


    }

};

int main()
{

    Graph g(10);

    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(1, 5);
    g.addEdge(2, 3);
    g.addEdge(2, 8);
    g.addEdge(2, 9);
    g.addEdge(3, 6);
    g.addEdge(4, 6);
    g.addEdge(4, 8);
    g.addEdge(5, 8);
    g.addEdge(6, 7);
    g.addEdge(7, 8);
    g.addEdge(8, 10);

    g.topologicalSort();

    return 0;
}
