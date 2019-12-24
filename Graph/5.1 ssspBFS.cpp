#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

//SSSP:single source shortest path is about to finding a a path between a given vertex (called a source)
       //and all other vertices in a graph . such that all distance between them is minimum.


// (BFS 0-1) shorted path to get shorted path form base node to all other nodes  in unweighted graph
const int OO= (int) 1e6;

void ssspBFS (int src,int des ,vvi adj){
     int n =adj.size();
     vi parent(n,-1),dist(n,OO);
     queue<int> q;
     q.push(src);dist[src]=0;
     while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int i=0; i < adj[cur].size() ;i++){
                 int u= adj[cur][i];
            if(dist[u] == OO){
                dist[u]=dist[cur]+1;
                parent[u]=cur;
                q.push(u);
            }
        }
     }
  //get path from src to des;
  if(dist[des] != OO){
    cout<<"the height from "<<src<<" to "<< des<<" "<< dist[des]<<endl;
  }
  else cout <<"there is no path"<<endl;
}

int main()
{     // zero index
     //input :7 8 5 4 4 3 4 0 0 5 5 2 2 4 2 1 2 6
     int n,e; cin>>n>>e;
    vector<vector<int> >adj (n);
     while(e--){
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
     }
     int src; cin>>src;
     ssspBFS(src,5,adj);

    return 0;
}
