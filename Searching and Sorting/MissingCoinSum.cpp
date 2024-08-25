#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
void solve(){
    vector<int> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    if(v[0]-1 >= 1){
        cout << 1;
        return;
    }
    ll s = 0;
    for(int i = 0; i < n-1; ++i){
        s += v[i];
        if(v[i+1]-v[i] > 1){
            int a = v[i]+1;
            while(a < v[i+1]){
                if(a > s){
                    cout << a;
                    return;
                }
                ++a;
            }
        }
    }
    cout << s + v.back()+1;
}
// 2 2 2 2
// 1 2 3 4

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    solve();
}
