#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main(){
    int n,s;
    cin>>n>>s;
    vector<int> v(n);
    for(int i = 0; i < n; ++i){
        cin>>v[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(s+1,0));
    for(int i = 0; i <= n; ++i){
        dp[i][0] = 1;
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= s; ++j){
            if(j >= v[i-1]){
                dp[i][j] = (dp[i-1][j] + dp[i][j-v[i-1]])%MOD;
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[n][s];
}
