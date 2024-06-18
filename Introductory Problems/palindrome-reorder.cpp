#include<bits/stdc++.h>
using namespace std;
 
int main(){
    string s;
    cin>>s;
    unordered_map<char,int> m;
    for(char &c : s){
        ++m[c];
    }
    int odd = 0, even = 0;
    for(auto &pair : m){
        if(pair.second % 2 == 0) ++even;
        else{
            ++odd;
        }
    }
    if(s.length()%2==0 && odd != 0){
        cout<<"NO SOLUTION";
        return 0;
    }else if(s.length()%2!=0 && odd != 1){
        cout<<"NO SOLUTION";
        return 0;
    }
    int left = 0, right = s.length()-1;
    char tmp;
    for(auto &pair : m){
        if(pair.second %2 != 0){
            tmp = pair.first;
            continue;
        }
        if(pair.second%2==0){
            while(pair.second){
                s[left++] = s[right--] = pair.first;
                pair.second -= 2;
            }
        }
    }
    for(int i = left; i <= right; ++i){
        s[i] = tmp;
    }
    cout<<s;
}
