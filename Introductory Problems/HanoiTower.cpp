#include<bits/stdc++.h>
using namespace std;

void solve(char start, char mid, char target, int n){
    if(n == 1){
        cout<<start<<" "<<target<<endl;
        return;
    }
    solve(start,target,mid,n-1);
    cout<<start<<" "<<target<<endl;
    solve(mid,start,target,n-1);
}

int main(){
    int n;
    cin >> n;
    cout<<pow(2,n)-1<<endl;
    solve('1','2','3',n);
}