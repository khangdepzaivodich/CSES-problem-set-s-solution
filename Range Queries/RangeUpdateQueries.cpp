#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,q;
void solve(){
    cin >> n >> q;
    vector<int> V(n);
    vector<int> D(n);
    for(auto &i : V) cin >> i;
    D[0] = V[0];
    for(int i = 1; i < n; ++i){
        D[i] = V[i] - V[i-1];
    }
    while(q--){
        int k;
        cin >> k;
        if(k == 1){
            int a,b,u;
            cin >> a >> b >> u;
            D[a-1] += u;
            if(b < n){
                D[b] -= u;
            }

        }else{
            int p;
            cin >> p;
            ll ans = 0;
            for(int i = 0; i < p; ++i){
                ans += D[i];
            }
            cout << ans << '\n';
        }
        
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}