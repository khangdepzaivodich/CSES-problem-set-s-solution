#include<bits/stdc++.h>
using namespace std;
 
int n;
 
void solve(){
    int a[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int ans = 1;
    vector<int> v;
    v.push_back(a[0]);
    for(int i = 1; i < n; ++i){
        if(a[i] >= v.back()){
            v.push_back(a[i]);
            ++ans;
        }else{
            int indx = upper_bound(v.begin(),v.end(),a[i]) - v.begin();
            v[indx] = a[i];
        }
    }
    cout << ans;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    solve();
}
