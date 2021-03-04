#include<bits/stdc++.h>
using namespace std;

// here we use dp to solve this problem
// time complexity of this code is O(n^2 * 2^n) which is less than O(n!) which is provide by naive solution
// here we use bit masking to track node is visited or not


int tsp(int graph[][4], int dp_mask[][4], int n, int visited_all, int mask, int pos)
{
    if(visited_all == mask)
        return graph[pos][0];

    if(dp_mask[mask][pos] != -1)
        return dp_mask[mask][pos];

    int ans = INT_MAX;

    for(int i = 0; i < n; i++)
    {
        if((mask & (1 << i)) == 0)
        {
            int newAns = graph[pos][i] + tsp(graph, dp_mask, n, visited_all, mask | (1<<i), i);
            ans = min(ans, newAns);
        }
    }

    return dp_mask[mask][pos] = ans;
}


int main()
{
    int graph[][4] = { { 0, 10, 15, 20 },
                       { 10, 0, 35, 25 },
                       { 15, 35, 0, 30 },
                       { 20, 25, 30, 0 } };

    int dp_mask[16][4];
    int n = 4;
    int visited_all = (1<<n) - 1;
    int mask = 1;
    int pos = 0;

    for(int i = 0; i < (1<<n); i++)
    {
        for(int j = 0; j<n; j++)
            dp_mask[i][j] = -1;
    }

    cout<<tsp(graph, dp_mask, n, visited_all, mask, pos);

    return 0;
}
