#include<bits/stdc++.h>
using namespace std;
 
int n, m;
int ans = 0;
 
void solve(){
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    int i = 0, j = n - 1;
    while (i <= j) {
        ++ans;
        if (v[i] + v[j] <= m){
            ++i;
            --j;
        } else{
            --j;
        }
    }
    
    cout << ans;
}
 
int main(){
    cin >> n >> m;
    solve();
}
