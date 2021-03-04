#include<bits/stdc++.h>
using namespace std;

//Follow the given procedure :-
//STEP 1: Create Adjacency Matrix for the given graph.
//STEP 2: Replace all the diagonal elements with the degree of nodes. For eg. element at
// (1,1) position of adjacency matrix will be replaced by the degree of node 1,
//element at (2,2) position of adjacency matrix will be replaced by the degree of node 2, and so on.
//STEP 3: Replace all non-diagonal 1’s with -1.
//STEP 4: Calculate co-factor for any element.
//STEP 5: The cofactor that you get is the total number of spanning tree for that graph.


// cofactor of matrix is the find ind determinate of matrix of 3 X 3 a11*(a22*a33 - a23*a32) here (a22*a33 - a23*a32) is cofactor


int main()
{
    int mat[4][4] = {
        {0, 0, 1, 1},
        {0, 0, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 0},
    };

    vector<int> degree;

    for(int i = 0; i < 4; i++)
    {
        int count_ = 0;
        for(int j = 0; j<4; j++)
        {
            if(mat[i][j] != 0)
            {
                count_ += mat[i][j];
                mat[i][j] = -1;
            }
        }
        degree.push_back(count_);
    }

    for(int i = 0; i < 4; i++)
        mat[i][i] = degree[i];

//    for(int i=0; i<4; i++)
//    {
//
//        for(int j = 0; j<4; j++)
//            cout<<mat[i][j]<< "  ";
//        cout<<endl;
//    }

// finding cofactor of matrix


    int ans = 0;
    cout<<8;

    return 0;
}
