#include<bits/stdc++.h>
using namespace std;

int maxJumpReach(int arr[], int n)
{

    int jump = 1;
    int steps = arr[0];
    int max_reachable = arr[0];

    for(int i = 1 ; i < n; i++)
    {
        if(i == n-1)
            return jump;

        steps--;
        max_reachable = max(max_reachable, i + arr[i]);

        if(steps == 0)
        {
            jump++;
            if(i >= max_reachable) return -1;

            steps = max_reachable - i;

        }
    }

    return jump;
}
int main()
{
    int arr[] = {1, 4, 3, 2, 6, 7};
    int n = 6;

    cout<<maxJumpReach(arr, n);


    return 0;
}
