#include<bits/stdc++.h>
using namespace std;

class Graph
{
    map<int , vector<int>> adj;

public:

    void addEdge(int w, int v)
    {
        adj[w].push_back(v);
    }

    void printingPathUsingBFS(int sorce, int destination)
    {
        queue<vector<int>> q;
        vector<int> path;
        vector<bool> visited (adj.size(), false);
        path.push_back(sorce);
        q.push(path);

        visited[sorce] = true;

        while(!q.empty())
        {
            path = q.front();
            q.pop();
            int last = path[path.size() - 1];
            if(last == destination)
            {
                for(int i = 0; i<path.size(); i++)
                    cout<< path[i]<< "  ";
                cout<<endl;
            }
            else
            {
                for(int x : adj[last])
                {
                    if(!visited[x])
                    {
                        vector<int> newPath(path);
                        newPath.push_back(x);
                        q.push(newPath);
                    }
                }
            }

        }

    }

};

int main()
{
    Graph g;

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);

    g.addEdge(2, 0);
    g.addEdge(2, 1);

    g.addEdge(1, 3);

    g.printingPathUsingBFS(2, 3);

    return 0;
}
