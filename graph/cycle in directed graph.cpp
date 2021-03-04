#include<bits/stdc++.h>
using namespace std;


class Graph
{
    int vertex;
    vector<int> *adj;
//  in this function rstack vector is used for to keep track current dfs call if we again reach same node which make dfs call that means cycle in this graph
//  to solve this problem we use this rstack vector
//  here we check for self loop also for that we use starting if statment
    bool isCycleUtil(int src, vector<bool> & visit, vector<bool> rstack)
    {
        if(visit[src])
            return false;
        visit[src] = true;
        rstack[src] = true;

        for(int x : adj[src])
        {
            if(!visit[x] && isCycleUtil(x, visit, rstack))
                return true;

            else if(rstack[x])
                return true;
        }

        rstack[src] = false;
        return false;

    }

public:

    Graph(int vertex)
    {
        this->vertex = vertex;
        adj = new vector<int>[vertex];
    }

    void addEdge(int w, int v)
    {
        adj[w].push_back(v);
    }

    bool isCycle()
    {
        vector<bool> visit(vertex, false);
        vector<bool> rstack(vertex, false);

        for(int i=0; i<vertex ; i++)
            if(isCycleUtil(i, visit, rstack))
                return true;

        return false;
    }

};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout<<g.isCycle();

    return 0;
}
