#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int vertex;
    vector<int> *adj;

    void topologicalUtil(int start, vector<bool> &visited, stack<int> & ans)
    {
        visited[start] = true;

        for(int x :adj[start])
        {
            if(!visited[x])
            {
                topologicalUtil(x, visited, ans);
            }
        }
        ans.push(start);
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
//        adj[v].push_back(w);
    }

    void topologicalSort()
    {
        vector<bool> v(vertex, false);
        stack<int> ans;

        for(int i = 0; i<v.size(); i++)
        {
            if(!v[i])
            {
                topologicalUtil(i, v, ans);
            }
        }

        while(!ans.empty())
        {
            cout<<ans.top()<< "  ";
            ans.pop();
        }
    }

};


int main()
{

    Graph g(6);

    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topologicalSort();

    return 0;
}
