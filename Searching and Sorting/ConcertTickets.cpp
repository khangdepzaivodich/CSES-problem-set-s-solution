#include <bits/stdc++.h>
using namespace std;

int n, m;

void solve() {
    multiset<int> tickets;
    for (int i = 0; i < n; ++i){
        int price;
        cin >> price;
        tickets.insert(price);
    }

    for(int i = 0; i < m; ++i){
        int max_price;
        cin >> max_price;
        auto it = tickets.upper_bound(max_price);
        if (it == tickets.begin()){
            cout << -1 << endl;
        }else{
            --it;
            cout << *it << endl;
            tickets.erase(it);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    solve();
}
