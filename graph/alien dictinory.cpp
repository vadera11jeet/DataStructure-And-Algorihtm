#include<bits/stdc++.h>
using namespace std;

// to find dictionary order of alien language we use topological sorting
// we find a mismatch char in addjecent vertex and add edge to those vertex
// then find their topological sorting

class Graph
{
    map<int, vector<int>> adj;

    void topologicalUtil(int src, vector<bool> & visited, stack<int> & s)
    {
        visited[src] = true;

        for(auto x : adj[src])
            if(!visited[x])
                topologicalUtil(x, visited, s);

        s.push(src);
    }

public:

    void addEdge(int w, int v)
    {
        adj[w].push_back(v);
    }


    void topologicalSorting()
    {
        vector<bool> visited(adj.size(), false);
        stack<int> s;


        for(int i = 0; i < adj.size(); i++)
            if(!visited[i])
                topologicalUtil(i, visited, s);

        while(!s.empty())
        {

            cout<< (char) (s.top() + 'a') << "  ";
            s.pop();

        }

    }
};


void printOrder(string w[], int size_)
{
    Graph g;

    for(int i = 0; i < size_ - 1; i++) // here size - 1 pair is possible so we use size - 1 not size
    {
        string s = w[i];
        string s2 = w[i+1];
        for(int j = 0; j < min(s.length(), s2.length()); j++)
        {
            if(s[j] != s2[j])
            {
                g.addEdge(s[j] - 'a', s2[j] - 'a');
                break;
            }
        }
    }


    g.topologicalSorting();

}

int main()
{

    string words[] = {"caa", "aaa", "aab"};
    printOrder(words, 3);
    return 0;
}
