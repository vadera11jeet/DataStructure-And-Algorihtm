#include<bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, vector<pair<int, int>>> adj;

    bool pathMoreThanKUtil(int src, int k, vector<bool> & visited)
    {
        if(k <= 0)
            return true;

        for(auto x : adj[src])
        {
            int dest = x.first;
            int weight = x.second;

            if(visited[dest])
                continue;

            if(weight >= k)
                return true;

            visited[dest] = true;

            if(pathMoreThanKUtil(dest, k - weight, visited))
                return true;

            visited[dest] = false;

        }

    }

public:

    void addEdge(int w, int v, int wt)
    {
        adj[w].push_back(make_pair(v, wt));
        adj[v].push_back(make_pair(w, wt));
    }

    bool pathMoreThanK(int src, int k)
    {
        vector<bool> visited(adj.size(), false);

        visited[src] = true;

        return pathMoreThanKUtil(src, k, visited);

    }


};


int main()
{

    Graph g;

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);


    g.pathMoreThanK(0, 62)? cout << "Yes\n" :
                             cout << "No\n";
    return 0;
}
