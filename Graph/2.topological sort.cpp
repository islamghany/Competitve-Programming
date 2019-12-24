#include <bits/stdc++.h>

using namespace std;

// topological sort algorithm
// if(some other node dependent on CurrentNode)  A --> B  then B depend on A
    //then go to that vertex first then come back to this vertex (recursion)   -> go to B and then come back to A
// else push CurrentNode in Stack

// implement by dfs

// only for Directed Acyclic Graph (DAG)
stack<int> s;
vector<vector<int> >adj;
vector<bool> vist;

// time :O(V+E)
// space:O(V+E)
void dfs(int v){
  if(vist[v]) return;
  vist[v]=1;
  for(int i=0;i<adj[v].size();i++){
    if(!vist[adj[v][i]]) dfs(v);
  }
  s.push(v);
}

void top_sort(int n){
  vist= vector<bool>(n);
  for(int i=0;i<n;i++){
    if(!vist[i]) dfs(i);
  }
  for(int i=0;i<n;i++){
    cout<<s.top()<<" ";
    s.pop();
  }
}

int main()
{     // zero index
     //input : 6 6 5 2 5 0 4 0 4 1 2 3 3 1
     int n,e; cin>>n>>e;
     adj=vector<vector<int> >(n);
     while(e--){
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
     }
     top_sort(n);

    return 0;
}
