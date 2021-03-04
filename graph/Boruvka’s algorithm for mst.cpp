#include<bits/stdc++.h>
using namespace std;

// complex city of this algorithm is O(ElogV)

class subset
{
public:

    int parent;
    int rank_;
};

int find_(vector<subset> & vec, int e)
{
    if(vec[e].parent != e)
        vec[e].parent = find_(vec, vec[e].parent);
    return vec[e].parent;
}

void union_(vector<subset> & vec, int x, int y)
{
    int x_ = find_(vec, x);
    int y_ = find_(vec, y);

    if(vec[x_].rank_ < vec[y_].rank_)
        vec[x_].parent = y_;

    else if(vec[x_].rank_ > vec[y_].rank_)
        vec[y_].parent = x_;

    else
    {
        vec[y_].parent = x_;
        vec[x_].rank_++;
    }
}

class Edge
{
public:

    int src;
    int dest;
    int weight;

    Edge(int src , int dest, int weight)
    {
        this->src = src;
        this->dest = dest;
        this->weight = weight;
    }

};

class Graph
{
    int vertex;
    vector<Edge> adj;
    int edge = 0;

public:

    Graph(int v)
    {
        vertex = v;
    }

    void addEdge(int w, int v, int y)
    {
        adj.push_back(Edge(w, v, y));
        edge++;
    }


    void boruvkaAlgo()
    {
        int ver = vertex;
        int edge = adj.size();

        vector<subset> s(ver);
        vector<int> cheap(vertex, -1);


        for(int i = 0; i < ver; i++)
        {
            s[i].parent = i;
            s[i].rank_ = 0;
        }

        int numTree  = ver;
        int mst = 0;
        while(numTree > 1)
        {
            for(int i = 0; i < ver; i++)
            {
                cheap[i] = -1;
            }

            for(int i = 0; i < edge; i++)
            {
                int s_ = find_(s, adj[i].src);
                int s2 = find_(s, adj[i].dest);

                if(s_ == s2)
                    continue;
                else
                {
                    if(cheap[s_] == -1 || adj[cheap[s_]].weight > adj[i].weight)
                        cheap[s_] = i;

                    if(cheap[s2] == -1 || adj[cheap[s2]].weight > adj[i].weight)
                        cheap[s2] = i;
                }
            }

            for(int i=0; i<ver; i++)
            {
                if(cheap[i] != -1)
                {
                    int s_ = find_(s, adj[i].src);
                    int s2 = find_(s, adj[i].dest);

                    if(s_ == s2)
                        continue;

                    mst += adj[cheap[i]].weight;

                    cout<< "edge included is  " <<adj[cheap[i]].src<< "  "<<adj[cheap[i]].dest<<endl;

                    union_(s, s_, s2);
                    numTree --;

                }
            }

        }
        cout<< "\nweight of MST is "<< mst<<endl;
    }

};


int main()
{
    Graph g(4);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    g.boruvkaAlgo();


    return 0;
}
