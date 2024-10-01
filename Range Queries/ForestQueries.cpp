#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,q;

void solve(){
    cin >> n >> q;
    vector<vector<int>> V(n+1,vector<int>(n+1,0));
    char c;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> c;
            if(c == '*'){
                V[i][j] = 1;
            }
        }
    }
    vector<vector<int>> prefix(n+1,vector<int>(n+1,0));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + V[i][j];
        }
    }
    while(q--){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        cout << prefix[c][d] - prefix[c][b-1] - prefix[a-1][d] + prefix[a-1][b-1] << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}