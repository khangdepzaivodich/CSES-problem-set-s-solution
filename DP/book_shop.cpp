#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,s;
    cin>>n>>s;
    vector<int> price(n);
    vector<int> page(n);
    for(int i = 0; i < n; ++i){
        cin>>price[i];
    }
    for(int i = 0; i < n; ++i){
        cin>>page[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(s+1));
    for(int i = 0; i <= n; ++i){
        dp[i][0] = 0;   
    }
    for(int i = 0; i <= s; ++i){
        dp[0][i] = 0;
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= s; ++j){
            if(j >= price[i-1]){
                dp[i][j] = max(dp[i-1][j], page[i-1]+dp[i-1][j-price[i-1]]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[n][s];
}