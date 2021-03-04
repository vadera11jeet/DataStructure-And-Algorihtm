#include<bits/stdc++.h>
using namespace std;

// time complexity of BFS is O(V+E)
// space complexity of BFS is O(V+E)


template<typename T>
class Graph
{
    map<T, list<T>> l;
public:

    void createEdge(T x, T y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void bfs(T src)
    {
//      maintained map for recored which node is visited or not
        map<T, bool> visited;
        queue<T> q;
//      other things are same as level order traversal in tree
        q.push(src);
        visited[src] = true;

        while(!q.empty())
        {
            T node = q.front();
            cout<<node<< "  ";
            q.pop();

            for(auto n : l[node])
            {
                if(!visited[n])
                {
                    q.push(n);
                    visited[n] = true;
                }
            }
        }
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

    g.bfs(0);

    return 0;
}
