#include<bits/stdc++.h>
using namespace std;

long long solve(vector<int> &v, int l, int r,vector<vector<long long>> &dp_0, vector<vector<long long>> &dp_1, bool turn = true){
    if(l == r){
        if(turn) return v[l];
        return 0;
    }
    if(turn){
        if(dp_1[l][r] != -1) return dp_1[l][r];
        dp_1[l][r] =  max(v[l]+solve(v,l+1,r,dp_0,dp_1,false),v[r]+solve(v,l,r-1,dp_0,dp_1,false));
        return dp_1[l][r];
    }else{
        if(dp_0[l][r] != -1) return dp_0[l][r];
        dp_0[l][r] = min(solve(v,l+1,r,dp_0,dp_1,true),solve(v,l,r-1,dp_0,dp_1,true));
        return dp_0[l][r];
    }
}

int main(){ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    vector<vector<long long>> dp_0(n+1,vector<long long>(n+1,-1));
    vector<vector<long long>> dp_1(n+1,vector<long long>(n+1,-1));
    cout << solve(v,0,n-1,dp_0,dp_1);
}