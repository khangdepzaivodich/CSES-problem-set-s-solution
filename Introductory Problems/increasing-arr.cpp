#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(ll i = 0; i<n; i++){
        cin>>a[i];
    }
    ll ans = 0;
    for(ll i = 0; i<n-1; i++){
        ll j = i+1;
        if(a[j]<a[i]){
            ans += a[i] - a[j];
            a[j] = a[i];
            
        }
 
    }
    cout<<ans;
}
