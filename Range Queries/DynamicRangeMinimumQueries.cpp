#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,q;
vector<int> tree;
void update(int k, int v){
    k += n;
    tree[k] = v;
    for(k /= 2; k >= 1; k /= 2){
        tree[k] = min(tree[k*2], tree[k*2+1]);
    }
}
int Min(int a, int b){
    a += n; b += n;
    int minn = INT_MAX;
    while(a <= b){
        if(a % 2 == 1) minn = min(minn, tree[a++]);
        if(b % 2 == 0) minn = min(minn, tree[b--]);
        a /= 2; b /= 2;
    }
    return minn;
}
 
void solve(){
    cin >> n >> q;
    vector<int> V(n);
    for(auto &i : V) cin >> i;
    tree.resize(2*n,INT_MAX);
    for(int i = 0 ; i < n; ++i){
        tree[n+i] = V[i];
    }
    for(int i = n - 1; i > 0; --i){
        tree[i] = min(tree[i*2], tree[i*2+1]);
    }
    int k,a,b;
    while(q--){
        cin >> k >> a >> b;
        if(k == 1){
            update(a-1,b);
        }else{
            cout << Min(a-1,b-1) << '\n';
        }
    }
}   
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
