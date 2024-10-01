#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n;
vector<int> V;
vector<ll> tree;
vector<int> tmp;
void build(int si, int st, int se){
    if(st == se){
        tree[si] = tmp[st];
        return;
    }
    int mid = (st + se) / 2;
    build(si * 2, st, mid);
    build(si*2+1, mid + 1, se);
    tree[si] = tree[si*2] + tree[si*2+1];
}

void query(int si, int st, int se, int val){
    if(st == se){
        cout << V[st] << " ";
        tmp[st] = 0;
    }else{
        int mid = (st + se) / 2;
        if(tree[si*2] >= val){
            query(si*2, st, mid, val);
        }else{
            query(si *2 + 1, mid + 1, se, val - tree[si*2]);
        }
    }
    if(st == se){
        tree[si] = tmp[st];
    }else{
        tree[si] = tree[si*2] + tree[si*2+1];
    }
}

void solve(){
    cin >> n;
    V.resize(n+1);
    tree.resize(4*n+1);
    tmp.resize(n+1,1);
    for(int i = 1; i <= n; ++i){
        cin >> V[i];
    }
    build(1,1,n);
    for(int i = 0; i < n; ++i){
        int q;
        cin >> q;
        query(1,1,n,q);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}