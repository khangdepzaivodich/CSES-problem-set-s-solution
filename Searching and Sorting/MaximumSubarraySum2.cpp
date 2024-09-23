#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,a,b;
void solve(){
    cin >> n >> a >> b;
    vector<int> V(n);
    for(int &i : V){
        cin >> i;
    }
    vector<ll> prefix(n+1,0);
    for(int i = 1; i <= n; ++i){
        prefix[i] = V[i-1] + prefix[i-1];
    }
    ll maxx = prefix[a];    
    deque<ll> Q;
    int j = 1; 
    Q.push_back(0);
    for(int i = a+1; i <= n; ++i){
        while(Q.size() && prefix[Q.back()] >= prefix[j]){
            Q.pop_back();
        }
        Q.push_back(j++);
        if(i - Q.front() > b){
            Q.pop_front();
        }
        maxx = max(maxx, prefix[i] - prefix[Q.front()]);
    }
    cout << maxx;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
