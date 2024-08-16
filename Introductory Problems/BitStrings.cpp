#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    long long ans = 1;
    while(n--){
        ans = ((ans % MOD) * (2 % MOD)) % MOD;
    }
    cout << ans;
}