#include<bits/stdc++.h>
using namespace std;

void DFSUtil(vector<vector<string>> & mat, int m, int n, int i, int j)
{
    if(i < 0 || i>= m || j < 0 || j >= n || mat[i][j] != "1")
        return ;

    mat[i][j] = "2";

    DFSUtil(mat, m, n, i-1, j);
    DFSUtil(mat, m, n, i+1, j);
    DFSUtil(mat, m, n, i, j+1);
    DFSUtil(mat, m, n, i, j-1);
}


int numIslands(vector<vector<string>> mat, int m, int n)
{
    int numOfIsland = 0;

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(mat[i][j] == "1")
            {
                DFSUtil(mat, m, n, i, j);
                numOfIsland++;
            }
        }
    }
    return numOfIsland;
}

int main()
{
    vector<vector<string>> mat   {
                                  {"1","1","0","0","0"},
                                  {"1","1","0","0","0"},
                                  {"0","0","1","0","0"},
                                  {"0","0","0","1","1"}
                                };


    cout<<numIslands(mat, 4, 5);
    return 0;
}
