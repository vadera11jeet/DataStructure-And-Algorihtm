#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int vertex ;
    vector<int> *adj;


    bool detectcycleUtil(vector<bool> & v, int parent, int src)
    {
        v[src] = true;

        for(int x : adj[src])
        {
            if(!v[x])
            {
                bool isCycle = detectcycleUtil(v, src, x);

                if(isCycle)
                    return true;

            }
            else if(x != parent)
                return true;

        }

        return false;
    }

public:

    Graph(int vertex)
    {
        this->vertex = vertex;
        adj = new vector<int> [vertex];
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    bool detectcycle()
    {
        vector<bool> visited (vertex, false);
        return detectcycleUtil(visited, -1, 0);
    }
};

int main()
{
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.detectcycle()?
       cout << "Graph contains cycle\n":
       cout << "Graph does n't contain cycle\n";

    return 0;
}
