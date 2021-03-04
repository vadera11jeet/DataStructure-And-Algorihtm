#include<bits/stdc++.h>
using namespace std;
#define V 4


bool safe(int mat[][V], vector<int> &color)
{
    for(int i = 0; i < V; i++)
        for(int j = i+1; j < V ; j++)
            if(mat[i][j] && color[i] == color[j])
                return false;
    return true;

}

bool isColoring(int mat[][4], int color, int i, vector<int>& colors)
{

    if(i == V)
    {
        if(safe(mat, colors))
        {
            for(int i : colors)
                cout<< i << "  ";
            cout<<endl;
            return true;
        }
        return false;
    }

    for(int j = 1; j<=color; j++)
    {
        colors[i] = j;

        if(isColoring(mat, color, i+1, colors))
            return true;

        colors[i] = 0;
    }

    return false;

}


int main()
{
    int  graph[V][V] = {
        { 0, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 0, 1, 0 },
    };


    vector<int> colors(V, 0);

     isColoring(graph, 3, 0, colors);

    return 0;
}
