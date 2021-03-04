#include<bits/stdc++.h>
using namespace std;

int minDistance(vector<int> dis, vector<bool> visit)
{
    int min_ = INT_MAX, minIndex ;

    for(int i = 0; i<dis.size(); i++)
    {
        if(dis[i] <= min_ && !visit[i])
            min_ = dis[i], minIndex = i;

    }
    return minIndex;
}

void Dijsktra(int graph[][9], int src)
{
    vector<int> dis(9, INT_MAX);
    vector<bool> proc(9, false);

    dis[src] = 0;

    for(int i = 0; i < 8; i++)
    {
        int small = minDistance(dis, proc);
        proc[small] = true;

        for(int j=0; j<9; j++)
        {
// here we check for is node is visited or not and check edge is exist or not and check smallest value is not INT_MAX and replace with it's smallest value
            if(!proc[j] && graph[small][j] != 0 && dis[small] != INT_MAX && (dis[small] + graph[small][j] < dis[j]))
                dis[j] = dis[small] + graph[small][j];
        }
    }

    for(int i = 0; i< 9; i++)
        cout<<i << "    "<< dis[i]<<endl;

}

int main()
{
    int graph[9][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    Dijsktra(graph, 0);

    return 0;
}
