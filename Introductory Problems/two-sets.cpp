#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    cin>>n;
    if((n*(n+1)/2)%2!=0){
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;
    int cnt = 0;
    vector<bool> check(n+1,false);
    ll t = 0;
    ll tmp = n*(n+1LL)/4;
    for(int i = n; i >= 1; --i){
        if(t + i <= tmp){
            check[i] = true;
            t += i;
            ++cnt;
        }
        if(t == tmp){
            break;
        }
    }
    cout<<n-cnt<<endl;
    for(int i = 1; i <= n; ++i){
        if(!check[i]){
            cout<<i<<" ";
        }
    }
    cout<<endl<<cnt<<endl;
    for(int i = 1; i <= n; ++i){
        if(check[i]){
            cout<<i<<" ";
        }
    }
 
}
