#include<bits/stdc++.h>
using namespace std;

//k core means connected component remain after removing all vertex with degree less than k

class Graph
{
    int vertex;
    vector<int> *adj;

public:

    Graph(int vertex)
    {
        this->vertex = vertex;
        adj = new vector<int> [vertex];
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

//  for display k-core we use DFS and cont degree and start with a vertex which has lowest degree

    bool dfsUtil(int src, vector<bool> & vist, vector<int> & degree, int k)
    {
        vist[src] = true;

        for(int x: adj[src])
        {

//   check degree of given vertex and reduce it's degree if less than k  than reduce degree of their nbr vertex
            if(degree[src] < k)
                degree[x]--;

//  check their further vertex is not visited
            if(!vist[x])
            {
//  now check the ancestor vertex and call further ancestor vertex and if they has less degree to given degree so reduce the degree
                if(dfsUtil(x, vist, degree, k))
                    degree[x]--;
            }

        }
        return degree[src] < k;
    }

    void prinKCore(int k)
    {
        int v = vertex;
        vector<int> degree(v);
        vector<bool> visit(v, false);

        int midDegree = INT_MAX;
        int startDegree;

        for(int i = 0; i<v; i++)
        {
            degree[i] = adj[i].size();

            if(degree[i] < midDegree)
            {
                midDegree = degree[i];
                startDegree = i;
            }
        }

        dfsUtil(startDegree, visit, degree, k);

        for(int i = 0; i< vertex; i++)
            if(!visit[i])
                dfsUtil(i, visit, degree, k);

        for(int i=0; i<v; i++)
        {
            if(degree[i] >= k)
            {
                cout<<endl<<i<<"  ";

                for(int i : adj[i])
                    if(degree[i] >= k)
                     cout<< " -> "<<i;
            }
        }
    }

    void bfs(int src)
    {
        map<int, bool> m;
        queue<int> q;

        q.push(src);
        m[src] = true;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            cout<<node;

            for(auto x : adj[node])
            {
                if(!m[x])
                {
                    q.push(x);
                    m[x] = true;
                }
            }
        }
    }
};

int main()
{
    int k = 3;

    Graph g1(9);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(1, 5);
    g1.addEdge(2, 3);
    g1.addEdge(2, 4);
    g1.addEdge(2, 5);
    g1.addEdge(2, 6);
    g1.addEdge(3, 4);
    g1.addEdge(3, 6);
    g1.addEdge(3, 7);
    g1.addEdge(4, 6);
    g1.addEdge(4, 7);
    g1.addEdge(5, 6);
    g1.addEdge(5, 8);
    g1.addEdge(6, 7);
    g1.addEdge(6, 8);

    g1.prinKCore(k);

    return 0;
}
