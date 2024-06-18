#include<bits/stdc++.h>
using namespace std;
 
int main(){
    long long n;
    cin>>n;
    long long s = (n*(n+1))/2;
    while(n>1){
        int k;
        cin>>k;
        s-=k;
        --n;
    }
    cout<<s;
}
