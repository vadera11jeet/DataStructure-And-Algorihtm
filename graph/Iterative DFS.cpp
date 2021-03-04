#include<bits/stdc++.h>
using namespace std;


class Graph
{
    int vertex;
    vector<int> *adj;

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

    void DFS(int src)
    {
        stack<int> s;
        map<int, bool> m;

        s.push(src);

        while(!s.empty())
        {
            int node = s.top();
            s.pop();

            if(!m[node])
            {
                cout<<node<< "  ";
                m[node] = true;
            }

            for(int x : adj[node])
                if(!m[x])
                    s.push(x);
        }
    }

};

int main()
{
    Graph g(5);

    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 4);

    g.DFS(0);

    return 0;
}
