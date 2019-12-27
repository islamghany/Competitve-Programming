#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<pair<int,int> > > vvi;
 vi d;


const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;
bool spfa(int s) {
    int n = adj.size();
    vector<int> cnt(n, 0);
    vector<bool> inqueue(n, false);
    queue<int> q;

    d[s] = 0;
    q.push(s);
    inqueue[s] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        inqueue[v] = false;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                if (!inqueue[to]) {
                    q.push(to);
                    inqueue[to] = true;
                    cnt[to]++;
                    if (cnt[to] > n)
                        return false;  // negative cycle
                }
            }
        }
    }
    return true;
}

/*
5 8
0 1 -1
0 2 4
1 2 3
1 3 2
1 4 2
3 2 5
3 1 1
4 3 -1
0*/
int main() {
    int n,m; cin>>n>>m;
    adj = vvi(n);
    d = vi(n,INF);
    while(m--){
        int v,u,w; cin>>v>>u>>w;
        adj[v].push_back(make_pair(u,w));
       // adj[u].push_back(make_pair(v,w));
    }
    int src; cin>>src;
    //vi dist;
    bool cycle= spfa(src);
    if(cycle){
        cout<<"the graph has no negative cycle"<<endl;
        for(int i =0;i<n;i++){
            cout<<i+1<<" : "<<d[i]<<endl;
        }
    }
    else{
          cout<<"the graph has negative cycle"<<endl;
        for(int i =0;i<n;i++){
            cout<<i+1<<" : "<<d[i]<<endl;
        }
    }
	return 0;
}
