#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int parent;
    int rank_;
};


int find_(int value, vector<Node> & dusf)
{
    if(dusf[value].parent == -1)
        return value;

    return dusf[value].parent = find_(dusf[value].parent, dusf);
}

void union_(int sorce, int dest, vector<Node> & dufs)
{
    if(dufs[sorce].rank_ > dufs[dest].rank_)
    {
        dufs[dest].parent = sorce;
    }
    else if(dufs[sorce].rank_ < dufs[dest].rank_)
    {
        dufs[sorce].parent = dest;
    }
    else
    {
        dufs[sorce].parent = dest;
        dufs[dest].rank_ += 1;
    }
}


bool isCyclic(vector<Node> dufs,vector<pair<int, int>> & edge, int vertex)
{
    for(auto x : edge)
    {
        int src = find_(x.first, dufs);
        int dest = find_(x.second, dufs);

        if(src == dest)
            return true;
        union_(src, dest, dufs);
    }
    return false;
}

int main()
{
    int e, v;
    cin>>e>>v;
    vector<Node> dufs(v);

    for(int i = 0; i<v; i++)
    {
        dufs[i].parent = -1;
        dufs[i].rank_ = 0;
    }

    vector<pair<int, int>> edge;



    return 0;
}
