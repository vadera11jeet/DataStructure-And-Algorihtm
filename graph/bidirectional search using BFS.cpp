#include<bits/stdc++.h>
using namespace std;
// this algorithm is improved version of BFS to find path in this algorithm start BFS from source as well as destination
// and find intersection point and print path this is improved version of bfs to find path it saves lot's of time

class Graph
{
    map<int, vector<int>> adj;

    void printPath(vector<int> s, vector<int> e, int intersecting, int st, int ed)
    {
        vector<int> path;
        path.push_back(intersecting);
// here we make this first array reverse because it give path us to intersection to start vertex so we must reverse this array
        int i = intersecting;
        while(i != st)
        {
            path.push_back(s[i]);
            i = s[i];
        }

        i = intersecting;
        reverse(path.begin(), path.end());

        while(i != ed)
        {
            path.push_back(e[i]);
            i = e[i];
        }

        for(int i = 0; i<path.size(); i++)
            cout<< path[i]<< "  ";
        cout<<endl;
    }


public:

    void addEdge(int w, int x)
    {
        adj[w].push_back(x);
        adj[x].push_back(w);
    }


    void byDirectionalSearch(int start, int end_)
    {

        vector<int> s_path(adj.size()), e_path(adj.size());
        queue<int> s_q, e_q;

        vector<bool> s_visited(adj.size(), false), e_visited(adj.size(), false);

        s_path[start] = -1;
        e_path[end_] = -1;

        s_q.push(start);
        e_q.push(end_);

        bool flag = false;

        s_visited[start] = true;
        e_visited[end_] = true;

        while(!s_q.empty() && !e_q.empty())
        {

            int s_node = s_q.front();
            int e_node = e_q.front();

            s_q.pop();
            e_q.pop();


            for(int x : adj[s_node])
            {
                if(!s_visited[x])
                {
                    s_q.push(x);
                    s_path[x] = s_node;
                    s_visited[x] = true;
                }
            }

            for(int x : adj[e_node])
            {
                if(!e_visited[x])
                {
                    e_q.push(x);
                    e_path[x] = e_node;
                    e_visited[x] = true;
                }
            }

            for(int i_ = 0; i_ < s_visited.size(); i_++)
            {

                if(s_visited[i_] && e_visited[i_])
                {
                    printPath(s_path, e_path, i_, start, end_);
                    flag = true;
                }

            }
            if(flag)
                break;

        }
        if(!flag)
            cout<< "path not exist\n";
    }

};


int main()
{
    Graph g;

    g.addEdge(0, 4);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 5);
    g.addEdge(4, 6);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(7, 8);
    g.addEdge(8, 9);
    g.addEdge(8, 10);
    g.addEdge(9, 11);
    g.addEdge(9, 12);
    g.addEdge(10, 13);
    g.addEdge(10, 14);

    g.byDirectionalSearch(0, 14);


    return 0;
}
