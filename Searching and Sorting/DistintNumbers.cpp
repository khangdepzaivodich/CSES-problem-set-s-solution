#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    set<int> visited;
    while(n--){
        int k;
        cin>>k;
        visited.insert(k);
    }
    cout<<visited.size();
}
