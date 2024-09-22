#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,a,b;
void solve(){
    cin >> n >> a >> b;
    vector<int> V(n);
    for(int &i : V) cin >> i;
    vector<int> P(a);
    sort(V.begin(),V.end());
    for(auto &i : P) cin >> i;
    sort(P.begin(),P.end());
    int i = 0, j = 0;
    int ans = 0;
    while(i < n && j < a){
        if(abs(V[i] - P[j]) <= b){
            ++ans;
            ++i;
            ++j;
        }else if(V[i] - P[j] > b){
            ++j;
        }else{
            ++i;
        }
    }
    cout << ans;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
