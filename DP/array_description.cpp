#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for(int i = 0; i < n; ++i){
        cin>>v[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    if(v[0] == 0){
        for(int i = 1; i <= m; ++i){
            dp[1][i] = 1;
        }
    }else{
        dp[1][v[0]] = 1;
    }
    for(int i = 2; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(v[i-1] == 0 || v[i-1] == j){
                if(j-1 >= 1) dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
                if(j+1 <= m) dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % MOD;
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            }
        }
    }
    int ans = dp[n][v[n-1]];
    if(v[n-1] == 0){
        for(int i : dp[n]){
            ans = (ans+i)%MOD;
        }
    }
    cout<<ans;
}