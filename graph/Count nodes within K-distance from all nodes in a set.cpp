#include<bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, vector<int>> adj;

public:

    void addEdge(int w, int v)
    {
        adj[w].push_back(v);
        adj[v].push_back(w);
    }


    void kThDistanceNode(int k, int src)
    {
        vector<bool> visited(adj.size(), false);

        queue<int> q;
        visited[src] = true;
        q.push(src);
        vector<int> kthlevel;

        while(!q.empty())
        {
            int temp = q.front();
            q.pop();

            if(k != 0)
            {
                for(int x : adj[temp])
                {
                    if(!visited[x])
                    {
                        q.push(x);
                        visited[x] = true;
                    }
                }
                k--;
            }
            else if(k == 0)
            {
                kthlevel.push_back(temp);
            }
        }

        for(int x : kthlevel)
            cout<<x<< "  ";
    }
};


int main()
{
    Graph g;

    g.addEdge(1, 0);
    g.addEdge(0, 3);
    g.addEdge(0, 8);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(3, 6);
    g.addEdge(3, 7);
    g.addEdge(4, 5);
    g.addEdge(5, 9);

    g.kThDistanceNode(2,2);


    return 0;
}
