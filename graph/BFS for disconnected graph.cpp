#include<bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, vector<int>> adj;

    void BFSUtil(vector<bool> &visited, int src)
    {
        queue<int> q;
        q.push(src);
        visited[src] = true;

        while(!q.empty())
        {
            int node = q.front();
            cout<<node<< "  ";
            q.pop();

            for(int x : adj[node])
            {
                if(!visited[x])
                {
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
    }

public:

    void addEdge(int w, int v)
    {
        adj[w].push_back(v);
    }


    void BFS()
    {
        vector <bool> visited (adj.size(), false);
        for(int i = 0; i< adj.size(); i++)
        {
            if(!visited[i])
                BFSUtil(visited, i);
        }
    }

};

int main()
{
    Graph g;

    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.BFS();

    return 0;
}
