#include<bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int src;
    int dest;
    int weight;

    Edge(int src, int dest, int weight)
    {
        this->src = src;
        this->dest = dest;
        this->weight = weight;
    }
};

bool compare(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}

int findParent(int v, vector<int> par)
{
    if(par[v] == -1)
        return v;
    return findParent(par[v], par);
}

void kruskal(vector<Edge> e, int n, int et)
{
    sort(e.begin(), e.end(), compare);

    vector<Edge> output;

    vector<int> parent(n, -1);
    int count_ = 0;

    for(int i = 0; count_!= n-1; i++)
    {
        Edge curr = e[i];

        int sourceParent = findParent(e[i].src, parent);
        int destParent = findParent(e[i].dest, parent);

        if(sourceParent != destParent)
        {
            output.push_back(curr);
            count_ ++;
            parent[sourceParent] = destParent;
        }

    }

    for(int i = 0; i <output.size(); i++)
    {
        cout<<output[i].src<< "  "<< output[i].dest<< "   "<<output[i].weight<<endl;
    }

}

int main()
{
    vector<Edge> e;

    e.push_back(Edge(1, 3, 1));
    e.push_back(Edge(0, 1, 2));
    e.push_back(Edge(0, 3, 3));
    e.push_back(Edge(0, 2, 4));
    e.push_back(Edge(4, 5, 5));
    e.push_back(Edge(2, 3, 6));
    e.push_back(Edge(3, 5, 7));
    e.push_back(Edge(2, 1, 8));
    e.push_back(Edge(2, 4, 9));
    e.push_back(Edge(2, 5, 10));
    e.push_back(Edge(3, 4, 11));

    kruskal(e, 6, 11);

    return 0;
}
