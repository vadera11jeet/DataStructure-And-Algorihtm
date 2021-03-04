#include<bits/stdc++.h>
using namespace std;


int find_(int v, vector<int> &dufs)
{
    if(dufs[v] == -1)
        return v;
    return find_(dufs[v], dufs);
}

void union_(int src, int dest, vector<int> &dufs)
{
    dufs[find_(src, dufs)] = find_(dest, dufs);
}

bool isCyclic(vector<pair<int, int>> &edge, vector<int>&dufs)
{
    for(auto x : edge)
    {
        int src = find_(x.first, dufs);
        int des = find_(x.second, dufs);

        if(src == des)
            return true;
        union_(src, des, dufs);
    }
    return false;
}

int main()
{
    int e;
    int v;
    cin>>e;
    cin>>v;

    vector<int> dufs(v, -1);

    vector<pair<int, int>> edge_list;

    for(int i = 0; i<e; i++)
    {
        int form, to;
        cin>>form>>to;
        edge_list.push_back({form, to});
    }

    cout<<isCyclic(edge_list,dufs);


    return 0;
}
