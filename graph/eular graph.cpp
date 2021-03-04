#include<bits/stdc++.h>
using namespace std;


class Graph
{
    int vertex;
    vector<int> *adj;

    void DFS(vector<bool> &visited, int src)
    {
        visited[src] = true;

        for(int x : adj[src])
        {
            if(!visited[x])
                DFS(visited, x);
        }

    }

    bool connectedGraph()
    {
//        here we make check that all edge in single component
        vector<bool> visited(vertex, false);
        int node = -1;

//       this loop is check for all the node have degree > 0 or not if none of the node have degree > 0 that means this graph does not have edge
        for(int i = 0; i <vertex; i++)
            if(adj[i].size() > 0)
            {
                node = i;
                break;
            }
// graph with 0 edge is always Euler graph
        if(node == -1)
            return true;

// DFS call to find total number of component in graph
        DFS(visited, node);

//  check for all edges of graph in single component or not if not than return false that means this graph is not Euler graph
        for(int i = 0; i< vertex; i++)
            if(adj[i].size() > 0 && !visited[i])
                return false;
        return true;

    }

    int find_Euler()
    {

        if(!connectedGraph())
            return 0;

        int odd = 0;

// here we count number of odd degree vertex
        for(int i = 0; i < vertex; i++)
            if(adj[i].size() & 1)
                odd++;

// if odd vertex are more than 2 that means that graph is not Euler graph
// if odd vertex is 0 than this graph is Euler graph
// if odd vertex are 2 than graph is semi Euler graph

        if(odd > 2)
            return 0;
        return (odd==0) ? 2 : 1;

    }

public:

    Graph(int vertex)
    {
        this->vertex = vertex;
        adj = new vector<int>[vertex];
    }

    void addEdge(int w, int v)
    {
        adj[w].push_back(v);
        adj[v].push_back(w);
    }

    void eularpath()
    {
        int t = find_Euler();
        cout<<t<<endl;
        if(t == 2)
            cout<< "Euler graph\n";
        if(t == 1)
            cout<< "semi Euler graph\n";
        else
            cout<< "not Euler graph\n";

    }

};



int main()
{
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);

    g1.eularpath();


    return 0;
}
