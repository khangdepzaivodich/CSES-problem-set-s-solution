#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main(){
    int n;
    cin>>n;
    vector<vector<char>> v(n,vector<char>(n));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin>>v[i][j];
        }
    }
    vector<vector<int>> dp(n,vector<int>(n,0));
    dp[0][0] = 1;
    if(v[0][0] == '*'){
        cout<<0;
        return 0;
    }
    if(n == 1){
        cout<<1;
        return 0;
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(j+1<n){
                if(v[i][j+1] != '*'){
                    dp[i][j+1] = (dp[i][j] + dp[i][j+1])%MOD;
                }
            }
            if(i+1<n){
                if(v[i+1][j] != '*'){
                    dp[i+1][j] = (dp[i][j] + dp[i+1][j])%MOD;
                }
            }
        }
    }
    cout<<dp[n-1][n-1];
}