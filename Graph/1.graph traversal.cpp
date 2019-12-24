#include <bits/stdc++.h>

using namespace std;

// bfs
//time:O(V+E)
//space: V+E

/*
Applications of BFS
• Finding all connected components in a graph
• Finding all nodes within one connected component
• Finding the shortest path between two nodes
• Testing a graph for bipartiteness
*/

vector< vector<int> > adj; // adjacency list representation
vector<bool> vist;
void bfs(int src){
  queue<int> q;
  q.push(src);
  while(!q.empty()){
    int cur = q.front(); q.pop();
    if(vist[cur]) continue;
    vist[cur] =1;
    cout<<cur<<" ";
    for(int i=0;i< adj[cur].size();i++){
        if(!vist[adj[cur][i]]){
            q.push(adj[cur][i]);
        }
    }
  }
}

// dfs
//time:O(V+E)
//space: V+E

/// DFS
/*
Applications of DFS
• Topological sorting
• Finding connected components
• Finding articulation points (cut vertices) of the graph
• Finding strongly connected components
• Solving puzzles such as mazes
*/


// implement with stack
void dfs(int src){
  stack<int> s;
 s.push(src);
 while(!s.empty()){
    int cur = s.top(); s.pop();
    if(vist[cur]) continue;
    vist[cur]=1;
    cout<<cur<<" ";
    for(int i =0;i<adj[cur].size();i++){
        if(!vist[adj[cur][i]])
            s.push(adj[cur][i]);
    }
 }
}

// implement with recursion (more efficient)
void dfs2(int src){
  if(vist[src]) return;
  vist[src]=1;
  cout<<src<<" ";
  for(int i=0;i<adj[src].size();i++){
    if( !vist[ adj[src][i] ] )
        dfs2(adj[src][i]);
  }
}
int main()
{    //7 6 5 4 4 3 4 0 5 2 2 1 2 6 5
    int v,e; cin>>v>>e;
    vist = vector<bool>(v);
    adj = vector< vector<int> >(v);
    while(e--){
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int src; cin>>src;
    bfs(src);
    vist = vector<bool>(v);
    cout<<endl;
    dfs(src);
    vist = vector<bool>(v);
    cout<<endl;
    dfs2(src);
    return 0;
}
