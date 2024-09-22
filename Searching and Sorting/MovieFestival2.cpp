#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,k;
bool cmp(pair<int,int> &p1, pair<int,int> &p2){
    return p1.second < p2.second;
}
void solve(){
    cin >> n >> k;
    vector<pair<int,int>> V(n);
    for(auto &i : V){
        cin >> i.first >> i.second;
    }
    sort(V.begin(),V.end(),cmp);
    int ans = 1;
    multiset<int> M;
    M.insert(V[0].second);
    for(int i = 1; i < n; ++i){
        auto it = M.upper_bound(V[i].first);
        if(it != M.begin() && M.size() <= k){
            ++ans;
            M.erase(--it);
            M.insert(V[i].second);
        }else if(M.size() < k){
            M.insert(V[i].second);
            ++ans;
        }
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
