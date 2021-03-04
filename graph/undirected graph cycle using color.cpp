#include<bits/stdc++.h>
using namespace std;

enum {WHITE, GRAY, BLACK};
class Graph
{
    map<int, vector<int>> adj;

    bool DFSUtil(int src, vector<int>& color)
    {
        color[src] = GRAY;

        for(auto x : adj[src])
        {
            if(color[x] == GRAY)
                return true;
            if(color[x] == WHITE && DFSUtil(x, color))
                return true;
        }
        color[src] = BLACK;
        return false;
    }

public:

    void addEdge(int w, int v)
    {
        adj[w].push_back(v);
    }

    bool cycleInGraph()
    {
        vector<int> color(adj.size(), WHITE);

        for(int i = 0; i< adj.size(); i++)
            if(color[i] == WHITE)
                if(DFSUtil(i, color))
                    return true;
        return false;
    }


};


int main()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout<<g.cycleInGraph();

    return 0;
}
