#include<bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int src;
    int des;
    int weight;

    Edge(int src, int des, int weight)
    {
        this->src = src;
        this->des = des;
        this->weight = weight;
    }
};

void bellmanFord(vector<Edge> & edge)
{
    vector<int> dist(5, INT_MAX);

    dist[0] = 0;


    for(int i = 0; i<5;i++)
    {
        for(int j =0; j< edge.size(); j++)
        {
            int u = edge[j].src;
            int v = edge[j].des;
            int wt = edge[j].weight;

            if(dist[u] != INT_MAX &&  dist[u] + wt < dist[v])
                dist[v] = dist[u] + wt;

        }
    }

    for(int j = 0; j<edge.size(); j++)
    {
            int u = edge[j].src;
            int v = edge[j].des;
            int wt = edge[j].weight;

            if(dist[u] != INT_MAX && dist[u]+ wt < dist[v])
            {
                cout<< "graph has negative edge cycle\n";
                return;
            }
    }

    for(int i = 0; i< dist.size(); i++)
        cout<<i << "  "<< dist[i]<<endl;
}

int main()
{
    vector<Edge> e;

    e.push_back(Edge(0, 1, -1));
    e.push_back(Edge(0, 2, 4));
    e.push_back(Edge(1, 2, 3));
    e.push_back(Edge(1, 3, 2));
    e.push_back(Edge(1, 4, 2));
    e.push_back(Edge(3, 2, 5));
    e.push_back(Edge(3, 1, 1));
    e.push_back(Edge(4, 3, -3));

    bellmanFord(e);



    return 0;
}
