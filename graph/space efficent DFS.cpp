#include<bits/stdc++.h>
using namespace std;

class Graph
{
    map<int , vector<int>> adj;

public:

    void addEdge(int w, int v)
    {
        adj[w].push_back(v);
        adj[v].push_back(w);
    }

// DFS without visited array this is also help to find cycle in grpah
    void DFS(int node, int arrival)
    {
        cout<< node<< "  ";

        for(int i = 0; i < adj[node].size(); i++)
        {
            if(adj[node][i] != arrival)
                DFS(adj[node][i], node);
        }
    }

};


int main()
{

    Graph g;

    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,5);

    g.DFS(1, 0);
    return 0;
}
