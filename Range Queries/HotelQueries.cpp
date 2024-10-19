#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> tree;
vector<int> v;

void build(int si, int st, int se){
    if(st == se){
        tree[si] = v[st];
        return;
    }
    int mid = (st + se) / 2;
    build(si*2,st,mid);
    build(si*2+1,mid+1,se);
    tree[si] = max(tree[si*2], tree[si*2+1]);
}
int query(int si, int st, int se, int val){
    if(st == se){
        tree[si] -= val;
        return st;
    }
    int mid = (st + se) / 2;
    int res;
    if(val <= tree[si*2]){
        res = query(si*2,st,mid,val);
    }else{
        res = query(si*2+1,mid+1,se,val);
    }
    tree[si] = max(tree[si*2], tree[si*2+1]);
    return res;
}

void solve(){   
    cin >> n >> m;
    v.resize(n+1);
    tree.resize(4*n+1);
    for(int i = 1; i <= n; ++i){
        cin >> v[i];
    }
    build(1,1,n);
    while(m--){
        int val;
        cin >> val;
        if(val > tree[1]){
            cout << 0 << ' ';
        }else{
            cout << query(1,1,n,val) << ' ';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}