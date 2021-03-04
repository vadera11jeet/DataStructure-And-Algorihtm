#include<bits/stdc++.h>
using namespace std;

class Graph
{
    unordered_map<string, list<pair<string,int>>> l;
public:

    void createEdge(string x="/0", string y="/0", bool byDir=true, int weight=INT_MIN)
    {
        l[x].push_back(make_pair(y, weight));

        if(byDir)
        {
            l[y].push_back(make_pair(x, weight)) ;
        }
    }

    void printEdge()
    {
        for(auto p : l)
        {
            string node = p.first;
            list<pair<string, int>> v = p.second;

            cout<<node<< " -> ";

            for(auto i : v)
            {
                cout<< i.first<< "  " <<i.second << " ,";
            }

            cout<<endl;
        }
    }

};

int main()
{
    Graph g;

    g.createEdge("1", "2", true, 50);
    g.createEdge("2", "4", true, 60);
    g.createEdge("1", "3", true, 80);
    g.createEdge("3", "4", true, 90);
    g.createEdge("1", "4", false, 30);

    g.printEdge();

    return 0;
}
