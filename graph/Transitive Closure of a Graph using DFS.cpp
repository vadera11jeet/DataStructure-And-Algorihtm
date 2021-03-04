#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int v;
    vector<int> *adj;

    void dfsUtil(vector<bool> &vec, int src)
    {
        vec[src] = true;

        for(auto x : adj[src])
            if(!vec[x])
                dfsUtil(vec, x);
    }

public:

    Graph(int v)
    {
        this->v = v;
        adj = new vector<int>[v];
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }

    void transitiveClosure()
    {
        vector<bool> visited(v, false);

        for(int i=0; i<v; i++)
        {
            dfsUtil(visited, i);
            for(int j = 0; j<v; j++)
                cout<<visited[j]<< "  ";
            cout<<endl;
            fill(visited.begin(), visited.end(), false);
        }
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

    g.transitiveClosure();

    return 0;
}
