#include<bits/stdc++.h>
using namespace std;



//       ********     ***********
//          **        **
//          **        **    *****
//          **        **       **
//       ********     ***********

#define faster             ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define module             int(1e9+7)
#define all(v)             v.begin(),v.end()
#define rall(v)            v.rbegin(),v.rend()
#define sz(v)              ((int)((v).size()))
#define psh(x)             push_back(x)
#define get(x)             cin>>x
#define out(x)             cout<<x<<endl
#define get2(x,y)          cin>>x>>t
#define idx(v,value)       find(v.begin(), v.end(), value ) - v.begin();
#define lop(i,n)           for(int i=0;i<n;++i)
#define loop(i,f,l)        for(int i=f;i<l;++i)
#define lopit(i,v)         for(i =v.begin(); i!= v.end() ; i++)
#define clr(v,d)           memset(v,d,sizeof(v))
#define mp                 make_pair
const double PI  = acos(-1.0);
const int OO= (int) 1e6;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef long long ll;
typedef vector<ll> vll;
typedef long double ld;
typedef unsigned long long int ull;
typedef ptrdiff_t pos;
typedef bitset<1000009> bit;

int N,M;

//// dirction
int dx[]={0,1,-1,1,-1,0,-1,1};
int dy[]={1,1,-1,0,0,-1,1,-1};
/// valid function
bool valid(int i,int j){return (i>=0 && i<N && j>=0 && j <=M ); }


/// DFS
/*
Applications of DFS
• Topological sorting
• Finding connected components
• Finding articulation points (cut vertices) of the graph
• Finding strongly connected components
• Solving puzzles such as mazes
*/

vvi v;
vb visited;
vi ans;
void dfs(int n){
  visited[n] =true;
  // cout<<n+1<<" ";
  for(int i=0;i<v[n].size();i++){
    int child = v[n][i];
    if(!visited[child]) dfs(child);
  }
  ans.psh(n);
}

void topology_sort(int n){
visited.assign(n,0);
//ans.clear();
lop(i,n){
if(!visited[i]) dfs(i);
}
reverse(all(ans));
lop(i,sz(ans)) cout<<ans[i]+1<<" ";
ans.clear();
}

//// Classification of edges of a graph
// 1) cycle edge if the out == -1;
// 2) forward edge if the start time of child node is bigger than current node;
// 3) else the edge is a cross edge

vvi adj;
vi start,out;
int idx=0;
void edgeClassification(int v){
  start[v]=idx++;
  lop(i,sz(adj[v])){
  int u= adj[v][i];
  if(start[u] == -1) edgeClassification(u);
  else{
    if(out[u] == -1) cout<<"cycle"<<v+1<<" "<<u+1<<endl;
    else if(start[u] > start[v]) cout<<"forward"<<v+1<<" "<<u+1<<endl;
    else cout<<"corss"<<v+1<<" "<<u+1<<endl;
  }
  }
  out[v]=idx++;

}

int ConnectedComponenetsCnt(int n)
{
	int cnt = 0;
	lop(i, n)
	{
		if(!visited[i])	// Then no one reach this isolated node yet and its neighbors.
		{
			dfs(i);
			cnt++;
		}
	}
	return cnt;
}

/// BFS

/*
Applications of BFS
• Finding all connected components in a graph
• Finding all nodes within one connected component
• Finding the shortest path between two nodes
• Testing a graph for bipartiteness
*/

vi BFS(int node,vvi &adj){
  vi l(sz(adj),OO);
  queue<int> q;
  q.push(node); l[node]=0;
  int cur=node,dep=0,s=1;
  for( ;!q.empty();dep++,s=q.size() ){
    while(s--){
        cur =q.front(); q.pop();
        lop(i,sz(adj[cur])){
            if(l[adj[cur][i] ]== OO) q.push(adj[cur][i]),l[adj[cur][i]] = dep+1;
        }
    }
  }
 return l; /// return the depth of every node;
}



/// Check if the graph is  Bipartite or not

void isbip(int s,int n,vvi adj){
 queue<int> q; q.push(s);
 vi color(n+1,OO); color[s]=0;
 while(!q.empty()){
    int u = q.front(); q.pop();
    lop(i,sz(adj[u])){
      int v =adj[u][i];
      if(color[v] == OO){
        color[v] =1 - color[u];
        q.push(v);
      }
      else if(color[v] == color[u]){
        cout<<"NOT BICOLORABLE."<<endl;
        return;
      }
    }
 }
 cout<<"BICOLORABLE."<<endl;
}


int main()
{
    /*
    int n,e;
  cin>>n>>e;
v = vvi(100);
//staOrt = vi(n,-1);
//out = vi(n,-1);
// visited = vb(n,false);
  while(e--){
    int f,t; cin>>f>>t;
    v[f-1].psh(t-1);
   // adj[f-1].psh(t-1);
  }
   topology_sort(n);
 // edgeClassification(0);
*/

//  check bipartite graph reader
/*
 int n,e;
   cin>>n;
  while(n){
  cin>>e;
  v = vvi(200);
  while(e--){
    int f,t; cin>>f>>t;
    v[f].psh(t);
  }
    isbip(0,n,v);
    cin>>n;
  }
  */
}
