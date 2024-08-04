#include <bits/stdc++.h>
using namespace std;

set<string> res;
void solve(string &s, string &current, vector<bool> &used) {
    if (current.size() == s.size()) {
        res.insert(current);
        return;
    }
    for (int i = 0; i < s.size(); ++i) {
        if (!used[i]) {
            current.push_back(s[i]);
            used[i] = true;
            solve(s, current, used);
            used[i] = false;
            current.pop_back();
        }
    }
}

int main() {
    string s;
    cin >> s;
    string current;
    vector<bool> used(s.size(), false);
    solve(s, current, used); 
    vector<string> sorted_res(res.begin(), res.end());
    sort(sorted_res.begin(), sorted_res.end());
    cout<<res.size()<<endl;
    for(string s : res){
        cout<<s<<endl;
    }
}
