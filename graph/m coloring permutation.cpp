#include<bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, vector<int>> adj;

    bool isSafe(vector<int>& color, int curr_color, int src)
    {
        for(int i : adj[src])
        {
//            cout<<color[i]<<endl;
            if(color[i] == curr_color)
                return false;
        }
        return true;
    }

    void graphColoringUtil(vector<int>&color, int m, int src, int v)
    {
        if(src == v)
        {

            for(int i = 0; i<v; i++)
            {
                cout<< color[i]<< "  ";

            }

            cout<<endl;
            return ;
        }

        for(int c = 1; c<= m; c++)
        {
            if(isSafe(color, c, src))
            {
                color[src] = c;
                graphColoringUtil(color, m, src+1, v);
                color[src] = 0;
            }
        }
        return;
    }



public:

    void addEdge(int w, int v)
    {
        adj[w].push_back(v);
        adj[v].push_back(w);
    }

    void graphColoring(int src, int m)
    {
//        cout<<adj.size()<<endl;
        vector<int> color(adj.size(), 0);
        src = 0;
        int v = adj.size();
        graphColoringUtil(color, m, 0, v);
//        for(int i : color)
//            cout<<i<< "  ";
    }

};


int main()
{
    Graph g;

    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(0,5);
    g.addEdge(1,2);
    g.addEdge(1,6);
    g.addEdge(2,3);
    g.addEdge(2,8);
    g.addEdge(3,9);
    g.addEdge(3,4);
    g.addEdge(4,7);
    g.addEdge(5,8);
    g.addEdge(5,9);
    g.addEdge(8,7);
    g.addEdge(6,7);
    g.addEdge(6,9);

    g.graphColoring(0, 3);

    return 0;
}
