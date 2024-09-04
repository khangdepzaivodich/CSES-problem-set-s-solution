#include<bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree <pair<int,int> ,  null_type , less<pair<int,int>> , rb_tree_tag , tree_order_statistics_node_update> orderSet;
#define ll long long
int n,t;
void solve(){
    int a[n];
    ll minn = INT_MAX;
    for(int i = 0; i < n; ++i){
        cin >> a[i];    
        minn = min(int(minn),a[i]);
    }
    minn *= t;
    ll left = 0, right = minn;
    ll mid;
    while(left <= right){
        mid = (left + right)/2;
        ll curProducts = 0;
        for(int &num : a){
            curProducts += mid/num;
        }
        if(curProducts < t){
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
    cin >> n >> t;
    solve();
}
