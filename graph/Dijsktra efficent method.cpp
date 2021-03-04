#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph
{
    unordered_map<T, vector<pair<T, int>>> m;
public:

  void addEdge(T u, T v, int dis, bool bidir = true)
  {
      m[u].push_back(make_pair(v, dis));
      if(bidir)
        m[v].push_back(make_pair(u, dis));
  }

  void printGraph()
  {
      for(auto x : m)
      {
          cout<<x.first<< " -> ";
          for(auto y : m[x.first])
            cout<<y.first<< "  "<< y.second;
          cout<<endl;
      }
  }

  void Dijsktra(T src)
  {
      map<T, int> dis;

      for(auto x : m)
      {
          dis[x.first] = INT_MAX;
      }

      set<pair<int, T>> s;
      dis[src] = 0;
      s.insert(make_pair(0, src));

      while(!s.empty())
      {
          auto p = *(s.begin()); // this will bring first pair of set

          int dis_ = p.first;
          T node = p.second;

          s.erase(s.begin());

          for(auto x : m[node])
          {
              T node_key = x.first;
              int node_dis = x. second;

              if(dis[node_key] > node_dis + dis_)
              {
                  auto f = s.find(make_pair(dis[node_dis], node_key));
                  if(f != s.end())
                  {
                      s.erase(f);
                  }
                  dis[node_key] = node_dis + dis_;
                  s.insert(make_pair(dis[node_key], node_key));
              }

          }

      }

      for(auto x : dis)
      {
          cout<<x.first<< " -> " << x.second<<endl;
      }
  }

};


int main()
{
//    Graph<int> g;

    //  making above shown graph
//    g.addEdge(0, 1, 4);
//    g.addEdge(0, 7, 8);
//    g.addEdge(1, 2, 8);
//    g.addEdge(1, 7, 11);
//    g.addEdge(2, 3, 7);
//    g.addEdge(2, 8, 2);
//    g.addEdge(2, 5, 4);
//    g.addEdge(3, 4, 9);
//    g.addEdge(3, 5, 14);
//    g.addEdge(4, 5, 10);
//    g.addEdge(5, 6, 2);
//    g.addEdge(6, 7, 1);
//    g.addEdge(6, 8, 6);
//    g.addEdge(7, 8, 7);
//
//    g.Dijsktra(0);

    Graph<int> g;
    g.addEdge(1,2,1);
    g.addEdge(1,3,4);
    g.addEdge(2,3,1);
    g.addEdge(3,4,2);
    g.addEdge(1,4,7);

    g.Dijsktra(1);

    return 0;
}

