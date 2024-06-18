#include<bits/stdc++.h>
using namespace std;
 
int main(){
    string s;
    cin>>s;
    int ans = 0;
    int cnt = 1;
    for(int i = 0; i<s.size(); i++){
        int j = i+1;
        if(s[i] == s[j]){
            ++cnt;
        }else{
            ans = max(ans,cnt);
            cnt = 1;
        }
    }
    cout<<ans;
}