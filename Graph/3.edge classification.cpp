#include <bits/stdc++.h>

using namespace std;

//// Classification of edges of a graph
// 1) cycle edge if the out == -1;
// 2) forward edge if the start time of child node is bigger than current node;
// 3) else the edge is a cross edge

vector<vector<int> >adj;
vector<int> start,out;
int idx=0;
void edge_classification(int v){
     start[v]=idx++;
     for(int i=0;i<adj[v].size();i++){
        int u = adj[v][i];
        if(start[u] == -1) edge_classification(u);
        else{
            if(out[u] == -1) cout<<"cycle "<<v<<" "<<u<<endl;
            else if(start[u] > start[v]) cout<<"forward "<<v<<" "<<u<<endl;
            else cout<<"cross "<<v<<" "<<u<<endl;
        }
     }
     out[v]=idx++;
}

int main()
{     // zero index
     //input :7 7 5 4 4 3 4 0 0 5 5 2 2 4 2 1 2 6
     int n,e; cin>>n>>e;
     adj=vector<vector<int> >(n);
     start=vector<int>(n,-1);
     out=vector<int>(n,-1);
     while(e--){
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
     }
     edge_classification(0);

    return 0;
}
