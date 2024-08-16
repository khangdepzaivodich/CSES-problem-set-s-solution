#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    long long s = 0;
    for(int i = 0; i < n; ++i){
        cin >> v[i];
        s += v[i];
    }       
    vector<long long> sum;
    sum.push_back(0);
    for(int num : v){
        vector<long long> current = sum;
        for(int i = 0; i < current.size(); ++i){
            sum.push_back(sum[i]+num);
        }
    }
    long long minn = s;
    for(int i = 1; i < sum.size(); ++i){
        minn = min(minn,abs((s-sum[i])-sum[i]));
    }
    cout << minn;
}