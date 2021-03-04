#include<bits/stdc++.h>
using namespace std;

// to find longest path in DAG we used topological sorting
// first of all we find topological ordering of graph
// we multiply all vertex weight with -1 and then we find shortest path
// for that we store value using dfs in stack and maintain a least and then we multiply -1 to value and store in vector and print vector
class Graph
{
    int vertex;
    vector<pair<int, int>> *adj;

    void longestPathinDAGUtil(stack<int> & s, vector<bool> & visited, int src)
    {
        visited[src] = false;

        for(auto x : adj[src])
        {
            if(!visited[x.first])
               longestPathinDAGUtil(s, visited, x.first);
        }

        s.push(src);
    }

public:

    Graph(int vertex)
    {
        this->vertex = vertex;
        adj = new vector<pair<int, int>> [vertex];
    }

    void addEdge(int src, int dest, int weight)
    {
        adj[src].push_back(make_pair(dest, weight));
    }

    void longestPathinDAG(int src)
    {
        vector<int> dest(vertex, INT_MAX);

        dest[src] = 0;

        vector<bool> visited(vertex, false);

        stack<int> s;

        for(int i = 0; i < vertex; i++)
            if(!visited[i])
                longestPathinDAGUtil(s, visited, i);

        while(!s.empty())
        {
            int st = s.top();
            s.pop();

            if(dest[st] != INT_MAX )
            {
                for(auto x : adj[st])
                {
                    if(dest[x.first] > dest[st] + x.second * -1)
                        dest[x.first] = dest[st] + x.second * -1;
                }
            }

        }


        for(int i = 0; i < vertex; i++)
        {
            if(dest[i] == INT_MAX)
            {
                cout<< "INT_MAX"<< "  ";
            }
            else
                cout<< dest[i] * - 1<< "  ";
        }

    }

};


int main()
{
        Graph g(6);

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    g.longestPathinDAG(1);

    return 0;
}
