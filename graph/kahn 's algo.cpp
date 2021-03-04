#include<bits/stdc++.h>
using namespace std;
// this algorithm is used for find topological sorting
// first of we find in-degree of all vertex in graph
// select all vertex which have 0 in-degree and push into queue and reduce in-degree of all adjacent vertex
// and increment count this loop run until queue become empty
// now we check if count == number of vertex in graph than we return topological sort else this graph is not DAG

class Graph
{
    int vertex;
    vector<int> *adj;
    vector<int> inDegree;


public:

    Graph(int vertex)
    {
        this->vertex = vertex;
        adj = new vector<int>[vertex];
        inDegree.resize(vertex);
    }

    void addEdge(int w, int v)
    {
        adj[w].push_back(v);
        inDegree[v]++;
    }

    void kahnAlgo()
    {
        queue<int> q;
        vector<int> ans;
        int count_ = 0;

        for(int i = 0; i < inDegree.size(); i++)
        {
            if(inDegree[i] == 0)
              q.push(i);
        }

        while(!q.empty())
        {
            int temp = q.front();
            q.pop();

            ans.push_back(temp);


            for(int x : adj[temp])
            {
                int d = inDegree[x] - 1;
                inDegree[x] --;
                if(d == 0)
                {
                    q.push(x);
                }
            }

            count_ ++;
        }

        if(count_ != vertex)
        {
            cout<< "there is cycle in graph\n";
            return;
        }

        for(int i = 0; i<ans.size(); i++)
            cout<<ans[i]<< "  ";
        cout<<endl;
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

    g.kahnAlgo();

    return 0;
}
