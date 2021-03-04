#include<bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, vector<int>> adj;

//  here we use DFS to visit graph
    void printAllPathUsingDFS(int start, int destination, vector<bool> & visited, vector<int>& path)
    {
//      mark node visited and add to vector path
        visited[start] = true;
        path.push_back(start);

//      check the given node is destination node if it is then print the path else check for all other vertex
        if(start == destination)
        {
            for(int i=0; i<path.size(); i++)
                cout<<path[i]<< "  ";
            cout<<endl;
        }
        else
        {
            for(auto x : adj[start])
            {
                if(!visited[x])
                {
                    printAllPathUsingDFS(x, destination, visited, path);
                }
            }
        }

//      here we remove current vertex and mark them unvisited because here it is mandatory to pass visited map and path vector as reference
//      because of else it will store all not needed path
//      the reason of marking unvisited is that if we can visit this node for another path
        path.pop_back();
        visited[start] = false;

    }


public:

    void addEdge(int w, int v)
    {
        adj[w].push_back(v);
    }

    void printAllPathsUsingDFS(int start, int destination)
    {
        vector<bool> visited(adj.size(), false);

        vector<int> path;

        printAllPathUsingDFS(start, destination, visited, path);
    }



};


int main()
{
    Graph g;

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(1, 3);

    g.printAllPathsUsingDFS(2, 3);

    return 0;
}
