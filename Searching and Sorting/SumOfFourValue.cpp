#include<bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree <pair<int,int> ,  null_type , less<pair<int,int>> , rb_tree_tag , tree_order_statistics_node_update> orderSet;
#define ln '\n'
#define ll long long
int n,a;
struct N{
    int num,pos;
};
bool cmp(N &n1, N &n2){
    return n1.num < n2.num;
}
void solve(){
    if(n <= 2){
        cout << "IMPOSSIBLE";
        return;
    }
    vector<N> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i].num;
        v[i].pos = i+1;
    }
    sort(v.begin(),v.end(),cmp);
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            int target = a - v[i].num - v[j].num;
            int k = j+1, l = n-1;
            while(k < l){
                ll s = v[k].num + v[l].num;
                if(s < target){
                    ++k;
                }else if(s > target){
                    --l;
                }else{
                    cout << v[i].pos << " " << v[j].pos << " " << v[k].pos << " " << v[l].pos;
                    return;
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
}
 
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> a;
    solve();
}
