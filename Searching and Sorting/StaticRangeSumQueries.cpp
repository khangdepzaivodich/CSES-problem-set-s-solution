#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,q;
void solve(){
    cin >> n >> q;
    vector<ll> V(n+1,0);
    for(int i = 1; i <= n; ++i){
        cin >> V[i];
        V[i] += V[i-1];
    }
    int a,b;
    while(q--){
        cin >> a >> b;
        cout << V[b] - V[a-1] << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
