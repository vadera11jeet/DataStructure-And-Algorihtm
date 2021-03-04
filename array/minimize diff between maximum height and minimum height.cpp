#include<bits/stdc++.h>
using namespace std;

int minimizeDiff(int arr[], int n, int k)
{

    vector<pair<int,int>> vec;
    vector<int> visited(n);

    for(int i = 0; i < n; i++)
    {
        if(arr[i] - k > 0)
        {
            vec.push_back({arr[i]-k, i});
        }
        vec.push_back({arr[i]+k, i});
    }

    sort(vec.begin(), vec.end());

    int ele = 0;
    int left = 0;
    int right = 0;

    while(ele < n && right < vec.size())
    {
        if(visited[vec[right].second] == 0)
            ele ++;
        visited[vec[right].second]++;
        right++;
    }

    int ans = vec[right - 1].first - vec[left].first;

    while(right < vec.size())
    {
        if(visited[vec[left].second] == 1)
            ele--;
        visited[vec[left].second] --;
        left++;

        while(ele < n && right < vec.size())
        {
            if(visited[vec[right].second] == 0)
                ele++;
            visited[vec[right].second]++;
            right++;
        }

        if(ele == n)
        {
            ans = min(ans, vec[right - 1].first - vec[left].first);
        }
        else
            break;
    }

    return ans;

}


int main()
{
    int arr[] = {1, 5, 8, 10};
    int n = 4;
    int k = 2;

    cout<<minimizeDiff(arr, n, k);

    return 0;
}
