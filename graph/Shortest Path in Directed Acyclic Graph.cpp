#include<bits/stdc++.h>
using namespace std;

// we use topological sorting to find shortest path in DAG


class Edge
{
public:
    int src;
    int dest;
    int wt;

    Edge(int src, int dest, int wt)
    {
        this->src = src;
        this->dest = dest;
        this->wt = wt;
    }

};

class Graph
{
    int vertex;
    vector<Edge> *adj;

    void topologicalUtil(int src, vector<bool> & visited, stack<int> & ans)
    {
        visited[src] = true;

        for(auto x : adj[src])
        {
            int y = x.dest;
            if(!visited[y])
                topologicalUtil(y, visited, ans);
        }

        ans.push(src);

    }

public:

    Graph(int vertex)
    {
        this->vertex = vertex;
        adj = new vector<Edge>[vertex];
    }

    void addEdge(int w, int v, int wt)
    {
        adj[w].push_back(Edge(w, v, wt));
    }


    void shortestPath(int src)
    {
        stack<int> s;
        vector<bool> visited(vertex, false);
        vector<int> dist(vertex ,INT_MAX);

        for(int i = 0; i < vertex; i++)
            if(!visited[i])
                topologicalUtil(i, visited, s);

        dist[src] = 0;

        while(!s.empty())
        {
            int temp = s.top();
            s.pop();
            cout<<temp<<endl;
            if(dist[temp] != INT_MAX)
            {
                for(auto x : adj[temp])
                {
                    int wt = x.wt;
                    if(dist[x.dest] > dist[temp] + wt)
                        dist[x.dest] = dist[temp] + wt;
                }
            }

        }

        for(int i = 0; i < vertex ; i++)
            dist[i] == INT_MAX ? cout<< "INT_MAX  ":cout<<dist[i]<< "  ";

    }

};



int main()
{

    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    g.shortestPath(1);

    return 0;
}
