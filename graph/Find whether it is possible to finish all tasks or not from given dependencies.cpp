#include<bits/stdc++.h>
using namespace std;

// this question is asked in google twitter and many companies
// this question is solved by two approaches 1) detect cycle using DFS 2) BFS using topological sorting

class Graph
{
    map<int, vector<int>> adj;
    int vertex;


    bool findCycleUtil(int src, vector<bool> & visited, vector<bool> & onpath)
    {
        visited[src] = onpath[src] = true;

        for(auto x : adj[src])
        {
            if(!visited[x] && findCycleUtil(x, visited, onpath))
                return true;
            else if(onpath[x])
                return true;
        }

        onpath[src] = false;
        return false;

    }

public:

   Graph(int vertex)
   {
       this->vertex = vertex;
   }

    void makeGraph(vector<pair<int, int>> pre)
    {
        for(auto x : pre)
            adj[x.second].push_back(x.first);
    }

    bool findCycle()
    {
        vector<bool> visited(vertex, false);
        vector<bool> nodeInPath(vertex, false);

        for(int i = 0; i < vertex; i++)
        {
            if(!visited[i] && findCycleUtil(i, visited, nodeInPath))
                return false;
        }
        return true;

    }
};

int main()
{
    vector<pair<int, int> > prerequisites;
    Graph g(4);

    prerequisites.push_back(make_pair(1, 0));
    prerequisites.push_back(make_pair(2, 1));
    prerequisites.push_back(make_pair(3, 2));

    g.makeGraph(prerequisites);
    g.findCycle() ? cout<< "it is possible\n" : cout<< "impossible\n" ;

    return 0;
}

