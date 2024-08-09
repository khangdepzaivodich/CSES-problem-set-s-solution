#include<bits/stdc++.h>
using namespace std;


int main(){
    string a, b;
    cin >> a >> b;
    vector<vector<int>> memo(a.length()+1,vector<int>(b.length()+1,0));
    for(int i = 0; i <= b.length(); ++i){
        memo[a.length()][i] = b.length() - i;
    }
    for(int i = 0; i <= a.length(); ++i){
        memo[i][b.length()] = a.length() - i;
    }
    for(int i = a.length() - 1; i >= 0; --i){
        for(int j = b.length() - 1; j >= 0; --j){
            if(a[i] == b[j]){
                memo[i][j] = memo[i+1][j+1];
            }else{
                memo[i][j] = min({1+memo[i][j+1],1+memo[i+1][j+1],1+memo[i+1][j]});
            }
            
        }
    }
    cout << memo[0][0];
}
