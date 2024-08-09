#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
#define ll long long
int main(){
    int t,n;
    cin>>t;
    vector<vector<ll>> dp(2, vector<ll>(1e6+1,0));
    dp[0][1] = dp[1][1] = 1;
    for(int i = 2; i <= 1e6; ++i){    
        dp[0][i] = (2*dp[0][i-1] + dp[1][i-1]) % MOD;
        dp[1][i] = (dp[0][i-1] + 4*dp[1][i-1]) % MOD;
    }
    while(t--){
        cin >> n;
        cout << (dp[0][n] + dp[1][n]) % MOD << endl;
    }
}