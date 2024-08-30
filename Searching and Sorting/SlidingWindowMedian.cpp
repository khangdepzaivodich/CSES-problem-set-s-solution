#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree <pair<int,int> ,  null_type , less<pair<int,int>> , rb_tree_tag , tree_order_statistics_node_update> orderSet;
int n,m;
void solve(){
    int a[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int i = 0, j = m-1;
    orderSet S;
    for(int z = 0; z < m; ++z){
        S.insert({a[z],z});
    }
    int mid = (m-1)/2;
    auto median = *S.find_by_order(mid);
    cout << median.first << " ";
    i = 1;
    j += 1;
    while(j < n){
        S.erase({a[i-1],i-1});
        S.insert({a[j],j});
        median = *S.find_by_order(mid);
        cout << median.first << " ";
        ++j;
        ++i;
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    solve();
}


