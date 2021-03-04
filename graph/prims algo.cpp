#include<bits/stdc++.h>
using namespace std;

int findMinimum(vector<int> value, vector<bool>s)
{
    int min_ = INT_MAX, ver;
    for(int i = 0; i< value.size(); i++)
    {
        if(!s[i] && min_ > value[i])
            min_ = value[i], ver = i;
    }
    return ver;
}


void findMST(int mat[][6], int src)
{
    vector<int> parent(6);
    vector<bool> setMST(6, false);
    vector<int> value(6, INT_MAX);


    value[src] = 0;
    parent[src] = -1;

    for(int i = 0; i<5; i++)
    {
        int small = findMinimum(value, setMST);
        setMST[small] = true;

        for(int j = 0; j<6; j++)
        {
            if(mat[small][j] != 0 && !setMST[j] && mat[small][j] < value[j])
            {
                value[j] = mat[small][j];
                parent[j] = small;
            }
        }
    }

    for(int i = 1; i< 5; i++)
        cout<<parent[i]<< " -> "<< i << " weight is "<< mat[i][parent[i]]<<endl;

}

int main()
{
    int graph[6][6] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };

    findMST(graph, 0);

    return 0;
}
