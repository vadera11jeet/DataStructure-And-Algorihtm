#include<bits/stdc++.h>
using namespace std;

void floydWarshall(int mat[][4])
{
    int solution[4][4];

    for(int i = 0; i<4; i++)
    {
        for(int j = 0; j<4; j++)
        {
            for(int k = 0; k<4 ;k++)
            {
                if(mat[j][i] == INT_MAX || mat[i][k] == INT_MAX )
                    continue;
                else if(mat[j][k] > mat[j][i] + mat[i][k])
                    mat[j][k] = mat[j][i] + mat[i][k];
            }
        }
    }

// if diagonal element is less than 0 than it means there is negative edge cycle
    for(int i = 0; i<4; i++)
        if(mat[i][i] < 0)
        {
            cout<< "there is negative edge weight cycle \n";
            return;
        }

    for(int i = 0; i< 4; i++)
    {
        for(int j = 0; j<4; j++)
        {
            if(mat[i][j] == INT_MAX)
                cout<< "INF"<< "  ";
            else
                cout<<mat[i][j]<< "  ";
        }
        cout<<endl;
    }

}


int main()
{

    int graph[4][4] = { {0, 5, INT_MAX, 10},
                        {INT_MAX, 0, 3, INT_MAX},
                        {INT_MAX, INT_MAX, 0, 1},
                        {INT_MAX, INT_MAX, INT_MAX, 0}
                    };

    floydWarshall(graph);

    return 0;
}
