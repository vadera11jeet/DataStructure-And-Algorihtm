#include<bits/stdc++.h>
using namespace std;


// here we using prims algorihm or krushkal algorihm but we modify weights of graph we take log of all weight of graph and then apply algorithm


int findMinimum(vector<int> & value, vector<bool> & s)
{
    int min_ = INT_MAX, ver;
    for(int i = 0; i< value.size(); i++)
    {
        if(!s[i] && min_ > value[i])
            min_ = value[i], ver = i;
    }
    return ver;
}


void findMinimumMST(int mat[][5], double logGraph[][5], int src=0)
{
    vector<bool> visited(5, false);
    vector<int> parent(5);
    vector<int> value(5, INT_MAX);

    parent[src] = -1;
    value[src] = 0;

    for(int i = 0; i < 5; i++)
    {
        int small = findMinimum(value, visited);
        visited[small] = true;

        for(int j= 0; j<5; j++)
        {
            if(logGraph[small][j] > 0 && !visited[j] && logGraph[small][j] < value[j])
            {
                parent[j] = small;
                value[j] = logGraph[small][j];
            }
        }
    }

    int minProduct =  1;
    cout<< "print edge weight\n";

    for(int i = 1; i<5; i++)
    {
        cout<<parent[i]<< "  "<< i << "  "<< mat[i][parent[i]]<<endl;

        minProduct *= mat[i][parent[i]];
    }
    cout<<endl<<minProduct;

}


void weightTolog(int graph[][5])
{
    double logGraph[5][5];
    int V = 5;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] > 0)
                logGraph[i][j] = log(graph[i][j]);
            else
                logGraph[i][j] = 0;
        }
    }

    findMinimumMST(graph, logGraph);

}


int main()
{

    int graph[5][5] = {
        { 0, 2, 0, 6, 0 },
        { 2, 0, 3, 8, 5 },
        { 0, 3, 0, 0, 7 },
        { 6, 8, 0, 0, 9 },
        { 0, 5, 7, 9, 0 },
    };


    weightTolog(graph);

    return 0;
}
