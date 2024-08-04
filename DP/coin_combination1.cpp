#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
long long coinCombination(int n, long long s, vector<long long> &v,vector<long long> &memo){
    if(s == 0) return 1;
    if(s < 0) return 0;
    if(memo[s] != -1) return memo[s];
    long long res = 0;
    for(int i = n - 1; i >= 0; --i){
        res += coinCombination(n,s-v[i],v,memo);
    }
    res %= MOD;
    memo[s] = res;
    return res;
}

int main(){
    int n,s;
    cin>>n>>s;
    vector<long long> v(n);
    vector<long long> memo(s+1,-1);
    for(int i = 0; i < n; ++i){
        cin>>v[i];
    }
    long long ans = coinCombination(n,s,v,memo);
    cout<<ans;
}