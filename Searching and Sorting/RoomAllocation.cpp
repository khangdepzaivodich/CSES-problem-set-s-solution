#include<bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree <pair<int,int> ,  null_type , less<pair<int,int>> , rb_tree_tag , tree_order_statistics_node_update> orderSet;
#define ln '\n'
#define ll long long
int n;
void solve(){
    cin >> n;
    vector<pair<pair<int,int>,int>> V(n);
    for(int i = 0; i < n; ++i){
        cin >> V[i].first.first >> V[i].first.second;
        V[i].second = i;
    }
    sort(V.begin(),V.end());
    multiset<pair<int,int>> S;
    vector<int> ans(n,-1);
    ans[V[0].second] = 1;
    S.insert({V[0].first.second,1});
    int roomId = 2;
    for(int i = 1; i < n; ++i){
        if(V[i].first.first > S.begin()->first){
            int num = S.begin()->second;
            ans[V[i].second] = num;
            S.erase(S.begin());
            S.insert({V[i].first.second,num});
        }else{
            ans[V[i].second] = roomId;
            S.insert({V[i].first.second,roomId++});
        }
    }
    cout << roomId-1 << ln;
    for(int &i : ans){
        cout << i << " ";
    }
}
 
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}

