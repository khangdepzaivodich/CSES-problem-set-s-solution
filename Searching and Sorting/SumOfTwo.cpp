#include<bits/stdc++.h>
using namespace std;

int n,x;
void solve(){
    vector<int> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    int i = 0, j = n-1;
    bool found = false;
    vector<int> tmp = v;
    sort(v.begin(),v.end());
    if(x < v[0]){
        cout << "IMPOSSIBLE";
        return;
    }
    int z,c;
    while(i < j){
        if(v[i] + v[j] == x){
            found = true;
            z = v[j];
            c = v[i];
            break;
        }else if(v[i] + v[j] > x){
            --j;
        }else{
            ++i;
        }   
    }
    if(!found){
        cout << "IMPOSSIBLE";
        return;
    }else{
        for(int i = 0; i < n; ++i){
            if(tmp[i] == z){
                cout << i+1 << " ";
                break;
            }
        }
        for(int i = n-1; i >= 0; --i){
            if(tmp[i] == c){
                cout << i+1 << " ";
                break;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    solve();
}