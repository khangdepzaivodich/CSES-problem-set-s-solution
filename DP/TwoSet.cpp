#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    if(n*(n+1)/2 % 2 != 0){
        cout << 0;
        return 0;
    }
    vector<vector<int>> dp(n+1,vector<int>(n*(n+1)/4+1,0));
    for(int i = 1; i <= n*(n+1)/4; ++i){
        dp[0][i] = 0;
    }
    for(int i = 0; i <= n; ++i){
        dp[i][0] = 1;
    }
    for(int i = 2; i <= n; ++i){
        for(int j = 1; j <= n*(n+1)/4-1; ++j){
            dp[i][j] = dp[i-1][j] % MOD;
            if(j >= i){
                dp[i][j] = (dp[i][j] + dp[i-1][j-i] % MOD) % MOD;
            }
        }
    }
    cout << dp[n][n*(n+1)/4-1];
}