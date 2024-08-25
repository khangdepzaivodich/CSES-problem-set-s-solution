#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
void solve(){
    vector<int> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    int m = v[n/2];
    ll s = 0;
    for(int num : v){
        s += abs(num-m);
    }
    cout << s;
}
// 1 2 2 3 5
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    solve();
}
