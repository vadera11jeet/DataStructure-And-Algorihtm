#include<bits/stdc++.h>
#define MAX  5
using namespace std;

// it is generally backtracking problem but here we use DFS concept first of all we visit a node than it's visit down left right up
void findPathInMaze(int m[][MAX], bool visited[][MAX], int row, int col, int n, vector<string> & result, string &ans)
{

     if(row < 0 || col >= n || visited[row][col] || m[row][col] == 0 || row >=n || col < 0)
    {
        return;
    }

    if(row == n-1 && col == n-1)
    {
        result.push_back(ans);
        return ;
    }

    visited[row][col] = true;

    ans.push_back('D');
    findPathInMaze(m, visited, row+1, col, n, result, ans);
    ans.pop_back();

    ans.push_back('L');
    findPathInMaze(m, visited, row, col-1, n, result, ans);
    ans.pop_back();

    ans.push_back('R');
    findPathInMaze(m, visited, row, col+1, n, result, ans);
    ans.pop_back();

    ans.push_back('U');
    findPathInMaze(m, visited, row-1, col, n, result, ans);
    ans.pop_back();


    visited[row][col] = false;

}



int main()
{

    int m[MAX][MAX] = { { 1, 0, 0, 0, 0 },
                        { 1, 1, 1, 1, 1 },
                        { 1, 1, 1, 0, 1 },
                        { 0, 0, 0, 0, 1 },
                        { 0, 0, 0, 0, 1 } };

    int n = sizeof(m) / sizeof(m[0]);

    bool visited[n][MAX];
    memset(visited, false, sizeof(visited));

    vector<string> result;
    string ans = "";

    findPathInMaze(m, visited, 0, 0, n, result, ans);

    for(int i = 0; i<result.size(); i++)
    {
        cout<<result[i]<<endl;
    }


    return 0;
}
