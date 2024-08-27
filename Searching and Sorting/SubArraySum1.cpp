#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,k;
void solve(){
    vector<int> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    int j = 0, i = 0;
    ll s = v[0];
    int ans = 0;
    while(i < n && j < n){
        if(s < k){
            ++i;
            s += v[i];
        }else if(s >= k){
            if(s == k) ++ans;
            s -= v[j];
            ++j;
        }
    }
    cout << ans;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;   
    solve();
}
