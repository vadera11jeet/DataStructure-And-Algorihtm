#include<bits/stdc++.h>
using namespace std;

// time complexity of DFS is O(V+E)
// space complexity of DFS is O(V+E)

template<typename T>

class Graph
{
    map<T, list<T>> l;

    void dfs_helper(T src, map<T, bool> & visited)
    {
        cout<<src<< "  ";
        visited[src] = true;

        for(auto n : l[src])
        {
            if(!visited[n])
                dfs_helper(n, visited);
        }

    }

public:

    void createEdge(T x, T y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void dfs(T src)
    {
        map<T, bool> visited;

        for(auto p : l)
        {
            T node = p.first;
            visited[node] = false;
        }

        dfs_helper(src, visited);

    }

};

int main()
{
    Graph<int> g;

    g.createEdge(0, 1);
    g.createEdge(0, 3);
    g.createEdge(1, 2);
    g.createEdge(2, 3);
    g.createEdge(3, 4);
    g.createEdge(4, 5);

    g.dfs(0);

    return 0;
}
