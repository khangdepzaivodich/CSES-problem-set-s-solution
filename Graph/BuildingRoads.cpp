#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], vector<bool> &vis, int i){
    vis[i] = 1;
    for(auto u : adj[i]){
        if(!vis[u]){
            dfs(adj,vis,u);
        }
    }
}
int n,m;
void solve(){
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i = 0; i < m; ++i){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<pair<int,int>> ans;
    vector<bool> vis(n+1,0);
    bool isFirst = true;
    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            if(isFirst){
                isFirst = false;
            }else{
                ans.push_back({i-1,i});
            }
            dfs(adj,vis,i);
        }
    }
    cout << ans.size() << '\n';
    for(auto p : ans){
        cout << p.first << " " << p.second << '\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}