#include<bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, vector<int>> adj;

public:

    void addEdge(int w, int v)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    void shortestPathUsingBFS(int src, int dest, vector<int> & path)
    {
        vector<bool> visited(adj.size(), false);
        vector<int> dist(adj.size(), INT_MAX);

        queue<int> q;
        q.push(src);

        dist[src] = 0;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            visited[node] = true;

            for(int x : adj[node])
            {
                if(!visited[x])
                {
                    q.push(x);
                    if(dist[x] > dist[node] + 1)
                    {
                        dist[x] = dist[node] + 1;
                        path[x] = node;
                    }

                    if(x == dest)
                    {
                        cout<<dist[dest];
                        return;
                    }

                }
            }
        }
        cout<< "path is not found"<<endl;
        return;
    }

};

int main()
{

    Graph g;

    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.addEdge(3, 7);
    g.addEdge(4, 5);
    g.addEdge(4, 6);
    g.addEdge(4, 7);
    g.addEdge(5, 6);
    g.addEdge(6, 7);

    int src = 0;
    int dest = 7;
    vector<int>path(8, INT_MAX);
    path.push_back(2);
    g.shortestPathUsingBFS(src, dest, path);
    cout<<endl;

    vector<int> path_;
    int temp  = dest;
    path_.push_back(temp);

    while(path[temp] != INT_MAX)
    {
        path_.push_back(path[temp]);
        temp = path[temp];
    }

    for(int i = path_.size() - 1; i>=0; i--)
        cout<<path_[i]<< "  ";

    return 0;
}
