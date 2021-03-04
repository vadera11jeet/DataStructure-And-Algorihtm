// this question is asked in adobe's interview question
// this problem is same as rat in maze (aka search in maze)
// here 0 means wall
// here 1 means source
// here 2 means destination
// here 3 means empty path

// solve this problem using BFS so first of all we create graph;

#include<bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, vector<int>> adj;

public:

    void addEdge(int w, int v)
    {
        adj[w].push_back(v);
        adj[v].push_back(w);
    }

    void printGraph()
    {
        for(auto x : adj)
        {
            cout<< x.first << " is connected with ";
            for(int y : adj[x.first])
                cout<< y << "  ";
            cout<<endl;
        }
    }

    void BFS(int source, int destination)
    {
        vector<int> visited(adj.size(), -1);
//        cout<< "hello\n";
        queue<int> q;
        q.push(source);
        visited[source] = 0;

        int count_ = 0;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(int x : adj[node])
            {
                if(visited[x] < 0 || visited[x] > visited[node] + 1)
                {
                    visited[x] =  visited[node] + 1;
                    q.push(x);
                }
            }
        }


            cout<<visited[destination]<< "  ";
    }
};

bool isValid(int start, int end_, int n, int cellValue)
{
    if(start < 0 || end_ >= n || start >= n || end_ < 0 || cellValue == 0 )
        return false;
    return true;
}

void minimumSteps(int maze[][3], int n)
{
    int s, d;
    int k = 1;
    Graph g;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(maze[i][j] != 0)
            {
//       here we are making graph from matrix for that we have to connect all element to their neighbor element
//       maze[0][0] first element is connected with maze[0][1] and maze[1][0]

//              this condition is for m[0][1] is connected with their neighbor element m[0][0] and m[0][2]
                if(isValid(i, j+1, n, maze[i][j+1]))
                    g.addEdge(k, k+1);
                if(isValid(i, j-1, n, maze[i][j-1]))
                    g.addEdge(k, k-1);

//              this condition is for connect boundary element with their previous row and next row m[0][0] connect with m[1][0] and m[2][0]
                if(j < n-1 && isValid(i+1, j, n, maze[i+1][j]))
                    g.addEdge(k, k+n);
                if(i > 0 && isValid(i-1, j, n, maze[i-1][j]))
                    g.addEdge(k, k-n);

            }
            if(maze[i][j] == 1)
                s = k;
            if(maze[i][j] == 2)
                d = k;
            k++;
        }
    }

    g.BFS(s, d);
}



int main()
{
    int M[3][3] = {{ 0 , 3 , 2 },
                   { 3 , 3 , 0 },
                   { 1 , 3 , 0 }};


    minimumSteps(M, 3);

    return 0;
}
