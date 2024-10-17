#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> dir = {-1, 0, 1, 0, -1};
void bfs(vector<vector<char>> &V, vector<vector<bool>> &vis, int r, int c){
    queue<pair<int,int>> q;
    q.push({r,c});
    vis[r][c] = 1;
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for(int d = 0; d < 4; ++d){
            int dRow = row + dir[d];
            int dCol = col + dir[d+1];
            if(dRow >= 0 && dRow < n && dCol >= 0 && dCol < m && !vis[dRow][dCol] && V[dRow][dCol] == '.'){
                vis[dRow][dCol] = 1;
                q.push({dRow,dCol});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<vector<char>> V(n, vector<char>(m));
    vector<vector<bool>> vis(n, vector<bool>(m,false));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> V[i][j];
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(!vis[i][j] && V[i][j] == '.'){
                ++cnt;
                bfs(V,vis,i,j);
            }
        }
    }
    cout << cnt;
}