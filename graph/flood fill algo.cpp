#include<bits/stdc++.h>
// this code is using DFS we can also do it by using BFS
using namespace std;

bool cellSafe(int source_row, int source_col, int n)
{
    if(source_col < 0 || source_col > n || source_row < 0 || source_row > n)
        return false;
    return true;
}


void floodFill(int mat[][8], int n, int value, int source_row, int source_col, int replace_value)
{
    if(mat[source_row][source_col] == value)
    {
        mat[source_row][source_col] = replace_value;

        if(cellSafe(source_row+1, source_col, n))
            floodFill(mat, n, value, source_row + 1, source_col, replace_value);

        if(cellSafe(source_row-1, source_col, n))
            floodFill(mat, n, value, source_row - 1, source_col, replace_value);

        if(cellSafe(source_row, source_col-1, n))
            floodFill(mat, n, value, source_row, source_col - 1, replace_value);

        if(cellSafe(source_row, source_col+1, n))
            floodFill(mat, n, value, source_row, source_col + 1, replace_value);
    }
    else
        return;
}

int main()
{
    int screen[8][8] = {
                {1, 1, 1, 1, 1, 1, 1, 1},
                  {1, 1, 1, 1, 1, 1, 0, 0},
                  {1, 0, 0, 1, 1, 0, 1, 1},
                  {1, 2, 2, 2, 2, 0, 1, 0},
                  {1, 1, 1, 2, 2, 0, 1, 0},
                  {1, 1, 1, 2, 2, 2, 2, 0},
                  {1, 1, 1, 1, 1, 2, 1, 1},
                  {1, 1, 1, 1, 1, 2, 2, 1},
                 };


    floodFill(screen, 8, screen[4][4], 4, 4, 3);

    for(int i = 0; i<8; i++)
    {
        for(int j = 0; j < 8; j++)
            cout<<screen[i][j]<< "  ";
        cout<<endl;
    }

    return 0;
}
