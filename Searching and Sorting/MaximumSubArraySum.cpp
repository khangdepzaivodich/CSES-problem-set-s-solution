#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n;
void solve(){
    vector<ll> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    ll s = v[0];
    ll maxx = s;
    for(int i = 1; i < n; ++i){
        if(s < 0){
            s = v[i];
        }else{
            s += v[i];
        }
        maxx = max(maxx,s);
    }
    cout << maxx;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    solve();
}
