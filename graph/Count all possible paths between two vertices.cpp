#include<bits/stdc++.h>
using namespace std;

// this code is find all possible path to given vertex
// here you get all all path including a vertex which you wanted all path

template<typename T>
class Graph
{
    int vertex;
    map<T, vector<T>> adj;

    void DFSUtil(T src, T pathTo, map<T, bool>  visited, int &numOfPath)
    {
        visited[src] = true;

        if(src == pathTo)
            numOfPath++;

        for(T x : adj[src])
        {
            if(!visited[x])
                DFSUtil(x, pathTo, visited, numOfPath);
        }
    }


public:

    Graph(int vetex)
    {
        this->vertex = vertex;
    }

    void addEdge(T w, T x)
    {
        adj[w].push_back(x);
        adj[x].push_back(w);
    }

    void BFS(int src)
    {
        map<T, bool> visited;
        queue<T> q;

        q.push(src);
        visited[src] = true;

        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            cout<< node<< "  ";

            for(auto x : adj[node])
            {
                if(!visited[x])
                {
                    q.push(x);
                    visited[x] = true;
                }
            }
        }
    }

    void DFS(int src)
    {
        map<T, bool> visited;
        int numOfPath = 0;

        for(auto x : adj)
        {
            T node = x.first;
            visited[node] = false;
        }

        T l ;
        for(auto x : adj)
        {
            l = x.first;
            DFSUtil(l, src, visited, numOfPath);
        }

        cout<<numOfPath;
    }

};

int main()
{
    Graph<int> g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 2);

    g.DFS(1);

    return 0;
}
