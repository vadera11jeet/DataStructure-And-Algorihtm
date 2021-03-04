#include<bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, vector<int>> adj;
    int edge;


    void listToAdjList(vector<vector<int>> vec)
    {
       for(int i = 0; i < vec.size(); i++)
       {
           adj[vec[i][0]].push_back(vec[i][1]);
           adj[vec[i][1]].push_back(vec[i][0]);
           edge += 1;
       }

    }

    void DfsUtil(vector<bool> & visited, int src)
    {
        visited[src] = true;

        for(int x : adj[src])
        {
            if(!visited[x])
                DfsUtil(visited, x);
        }
    }

public:

    void makeConnection(vector<vector<int>> vec, int n)
    {
        listToAdjList(vec);
        vector<bool> visited(n, false);
        int num_of_components = 0;

        if(edge < n - 1)
        {
            cout<< " not possible\n";
            return;
        }

        for(int i = 0; i<visited.size(); i++)
        {
            if(!visited[i])
            {
                DfsUtil(visited, i);
                num_of_components ++;
            }
        }
        int redundant = edge - ((n - 1) - (num_of_components -  1));

        if(redundant >= (num_of_components - 1))
        {
            cout<< num_of_components - 1<<endl;
            return;
        }

        cout<< "not possible\n";
        return ;
    }
};


int main()
{

    int arr[5][2] = {{0,1},{0,2},{0,3},{1,2},{1,3}};
    vector<vector<int> > vec;
    vector<int> temp;
    for(int i = 0; i<5; i++)
    {
        for(int j = 0; j<2; j++)
        {
            temp.push_back(arr[i][j]);
        }
        vec.push_back(temp);
        temp.pop_back();
        temp.pop_back();
    }

    Graph g;

    g.makeConnection(vec, 6);

    return 0;
}
