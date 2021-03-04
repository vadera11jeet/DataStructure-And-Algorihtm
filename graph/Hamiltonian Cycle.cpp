#include<bits/stdc++.h>
using namespace std;



class Graph
{
    map<int, vector<int>> adj;

    bool hemiltonialCycleUtil(int src, vector<bool> & visited, vector<int> & ans)
    {
        if(ans.size() == adj.size())
            return true;

        for(int x : adj[src])
        {
            if(!visited[x])
            {
                visited[x] = true;
                ans.push_back(x);
                if(hemiltonialCycleUtil(x, visited, ans))
                    return true;

                visited[x] = false;
                ans.pop_back();
            }
        }

        return false;
    }

public:

    void addEdge(int w, int v)
    {
        adj[w].push_back(v);
        adj[v].push_back(w);
    }

    void hemiltonialCycle(int src)
    {
        vector<bool> visited(adj.size(), false);
        vector<int> ans;
        ans.push_back(src);
        visited[src] = true;
        if(hemiltonialCycleUtil(src, visited, ans))
        {
            for(int x : ans)
                cout<<x<< "  ";
            cout<<ans[0]<<endl;

        }
    }
};

int main()
{
    Graph g;

    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 4);

    g.hemiltonialCycle(0);

    Graph g1;

    g1.addEdge(0, 1);
    g1.addEdge(0, 3);
    g1.addEdge(1, 2);
    g1.addEdge(1, 3);
    g1.addEdge(1, 4);

    cout<< "g1 graph "<<endl;
    g1.hemiltonialCycle(0);

    return 0;
}
