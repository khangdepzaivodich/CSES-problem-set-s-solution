#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>v(n);
    for(int i=0;i<n;++i)cin>>v[i];
    set<int> s;
    s.insert(0);
    for(int &num : v){
        vector<int> current(s.begin(),s.end());
        for(int d : current){
            s.insert(num+d);
        }
    }
    cout << s.size()-1 << endl;
    for(int num : s){
        if(num != 0) cout << num << " ";
    }
}