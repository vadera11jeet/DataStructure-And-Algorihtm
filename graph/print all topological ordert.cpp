#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int vertex;
    vector<int> *adj;
    vector<int> inDegree;

    void allTopologicalUtil(vector<bool> & visited, vector<int>&ans)
    {
        bool flag = false;

        for(int i = 0; i < vertex; i++)
        {
            if(inDegree[i] == 0 && !visited[i])
            {
                for(int x : adj[i])
                {
                    inDegree[x]--;
                }

                ans.push_back(i);

                visited[i] = true;
                allTopologicalUtil(visited, ans);

                visited[i] = false;
                ans.erase(ans.end() - 1);

                for(int x : adj[i])
                    inDegree[x]++;
                flag = true;

            }
        }

        if(!flag)
        {
            for(int i = 0; i<ans.size(); i++)
                cout<< ans[i]<< "  ";
            cout<<endl;
        }

    }


public:

    Graph(int vertex)
    {
        this->vertex = vertex;
        adj = new vector<int>[vertex];
        inDegree.resize(vertex);
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        inDegree[w]++;
    }

    void allTopological()
    {
        vector<bool> visited(vertex, false);
        vector<int> ans;

        allTopologicalUtil(visited, ans);

    }

};

int main()
{

    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout<< "all topological sorting\n";

    g.allTopological();

    return 0;
}
