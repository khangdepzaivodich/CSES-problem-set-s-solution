#include<bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree <pair<int,int> ,  null_type , less<pair<int,int>> , rb_tree_tag , tree_order_statistics_node_update> orderSet;
#define ln '\n'
#define ll long long
int n,x;
void solve(){
    vector<int> v(n);
    ll left = -1;
    for(auto &i : v){
        cin >> i;
        left = max(int(left),i);
    }
    ll right = 1e18;
    ll mid;
    while(left <= right){
        mid = (right + left) / 2;
        int cnt = 1;
        ll s = 0;
        for(int i = 0; i < n && cnt <= x; ++i){
            s += v[i];
            if(s > mid){
                ++cnt;
                s = v[i];
            }
        }
        if(cnt > x){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    cout << left;
}
 
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    solve();
}
