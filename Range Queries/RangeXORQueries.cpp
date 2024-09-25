#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,q;
vector<int> tree;
int s(int a, int b){
    bool isFirst = true;
    int sum = 0;
    a += n; b += n;
    while(a <= b){
        if(a % 2 == 1) sum ^= tree[a++];
        if(b % 2 == 0) sum ^= tree[b--];
        a /= 2; b /= 2;
    }
    return sum;
}

void solve(){
    cin >> n >> q;
    vector<int> V(n);
    for(auto &i : V) cin >> i;
    tree.resize(2*n,0);
    for(int i = 0 ; i < n; ++i){
        tree[n+i] = V[i];
    }
    for(int i = n - 1; i > 0; --i){
        tree[i] = tree[2*i] ^ tree[2*i+1];
    }
    int a,b;
    while(q--){
        cin >> a >> b;
        cout << s(a-1,b-1) << '\n';
    }
}   

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}