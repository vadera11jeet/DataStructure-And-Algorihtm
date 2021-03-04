#include<bits/stdc++.h>
using namespace std;


template<typename T>
class Graph
{
    map<T, vector<T>> adj;

    void DFSUtil(int src, map<T, bool>& visited)
    {
        visited[src] = true;

        for(auto x : adj[src])
        {
            if(!visited[x])
                DFSUtil(x, visited);
        }

    }

public:

    void addEdge(T w, T v)
    {
        adj[w].push_back(v);
    }

    void DFS(T src)
    {
        map<T, bool> visited;

        for(auto x : adj)
        {
            T node = x.first;
            visited[node] = false;
        }

    }

    void BFS(T src)
    {
        queue<T> q;
        q.push(src);
        map<T, bool> m;

        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            m[node] = true;
            cout<<node<< "  ";

            for(T x : adj[node])
            {
                if(!m[x])
                {
                    q.push(x);
                    m[x] = true;
                }
            }
        }
    }

    map<T, vector<T>> transposeGraph()
    {
        map<T, vector<T>> i;

        for(const auto & x : adj)
        {
            for(auto y : adj[x.first])
            {
                i[y].push_back(x.first);
            }
        }

        return i;
    }

    void printGraph()
    {
        for(auto x : adj)
        {
            T first = x.first;
            vector<T> y = x.second;
            cout<< first<< " -> ";
            for(auto v : y)
                cout<< v << "  ";
            cout<<endl;
        }
    }
    void printGraph(map<T, vector<T>> adj)
    {
        for(auto x : adj)
        {
            T first = x.first;
            vector<T> y = x.second;
            cout<< first<< " -> ";
            for(auto v : y)
                cout<< v << "  ";
            cout<<endl;
        }
    }
};

int main()
{
    Graph <int> g;

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(0, 3);
    g.addEdge(2, 0);
    g.addEdge(3, 2);
    g.addEdge(4, 1);
    g.addEdge(4, 3);

    g.printGraph();
    map<int, vector<int>> m = g.transposeGraph();
    cout<< "transpose\n";
    g.printGraph(m);

    return 0;
}

