#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,q;
vector<int> S;
void build(int si, int st, int se, vector<int> &V){
    if(st == se){
        S[si] = V[st];
        return;
    }
    int mid = (st + se) / 2;
    build(si*2,st,mid,V);
    build(si*2+1,mid+1,se,V);
 
    S[si] = min(S[si*2], S[si*2+1]);
}
int query(int si, int st, int se, int qs, int qe){
    if(qe < st || qs > se) return INT_MAX;
    if(qs <= st && qe >= se) return S[si];
    int mid = (st + se) / 2;
    int left = query(si*2,st,mid,qs,qe);
    int right = query(si*2+1,mid+1,se,qs,qe);
    return min(left, right);
}
void solve(){
    cin >> n >> q;
    vector<int> V(n);
    S.resize(4*n);
    for(auto &i : V) cin >> i;
    build(1,0,n-1,V);
    int a,b;
    while(q--){
        cin >> a >> b;
        cout << query(1,0,n-1,a-1,b-1) << '\n';
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
