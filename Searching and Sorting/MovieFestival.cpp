#include<bits/stdc++.h>
using namespace std;

int n;
bool cmp(pair<int,int> e1, pair<int,int> e2){
    return e1.second < e2.second;
}
void solve(){
    vector<pair<int,int>> events;
    for(int i = 0; i < n; ++i){
        int start, end;
        cin >> start >> end;
        events.push_back({start,end});
    }
    sort(events.begin(),events.end(),cmp);
    int ans = 1;
    int i = 0, j = 1;
    while(i < n && j < n){
        if(events[j].first >= events[i].second){
            ++ans;
            i = j;
        }
        ++j;
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    solve();
}