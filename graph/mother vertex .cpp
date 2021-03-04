// a vertex is known as mother vertex if and only if from this vertex path exist to every other vertex
#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int v;
    vector<int> *l;

    void dfsUtil(vector<bool> &v, int src)
    {
        v[src] = true;

        for(auto x :l[src])
            if(!v[x])
                dfsUtil(v, x);
    }

public:

    Graph(int v)
    {
        this->v = v;
        l = new vector<int>[v];
    }

    void addEdge(int x, int y)
    {
        l[x].push_back(y);
    }

// to find mother vertex we use DFS traversal

    int motherVertex()
    {
//      here we maintain visited vector to mark visit
        vector<bool> ve( v, false);
        int last_dfs = 0;

//      and call DFS for all nodes in graph and save last DFS called node
        for(int i = 0; i<ve.size(); i++)
        {
            if(!ve[i])
            {
                dfsUtil(ve,i);
                last_dfs = i;
            }
        }
//      now we mark all vector to false and called

        fill(ve.begin(), ve.end(), false);

//      then we call DFS again
        dfsUtil(ve, last_dfs);
//       if this vertex is mother vertex than whole array become array of true
        for(int i = 0; i< ve.size(); i++)
        {
            if(!ve[i])
            {
                return -1;
            }
        }
        return last_dfs;
    }

};


int main()
{
    Graph g(7);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 1);
    g.addEdge(6, 4);
    g.addEdge(5, 6);
    g.addEdge(5, 2);
    g.addEdge(6, 0);

    cout<< g.motherVertex();


    return 0;
}
