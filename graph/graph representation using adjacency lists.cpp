#include<bits/stdc++.h>
using namespace std;

// here we use adjacency list method to represent graph
// for that we need to maintain a list for every vertex in graph
// this is only for undirected graph

class Graph
{
    int vertex;
    vector<int> * l; // so maintain list of list we use pointer to a vector which holds vector of integer as member

    public:

        Graph(int ver)
        {
            vertex = ver;
            l = new vector<int>[ver];
        }

        void creatEdge(int start, int end_)
        {
            l[start].push_back(end_);
            l[end_].push_back(start);
        }

        void printAllEdge()
        {
            for(int i=0; i<vertex; i++)
            {
                cout<< "vertex " <<i << " connected with vertex "<< "->"<< "  ";
                for(auto j : l[i])
                {
                    cout<<j<<"  ";
                }
                cout<<endl;
            }
        }

};


int main()
{
    Graph g(4);

    g.creatEdge(0, 1);
    g.creatEdge(1, 2);
    g.creatEdge(2, 3);
    g.creatEdge(3, 0);

    g.printAllEdge();

    return 0;
}
