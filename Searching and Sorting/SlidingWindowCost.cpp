#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree <pair<int,int> ,  null_type , less<pair<int,int>> , rb_tree_tag , tree_order_statistics_node_update> orderSet;
#define ll long long
int n,m;
void solve(){
    int a[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int i = 0, j = m-1;
    orderSet S,S1;
    for(int z = 0; z < m; ++z){
        S.insert({a[z],z});
    }
    int mid = (m-1)/2;
    auto median = *S.find_by_order(mid);
    ll sum = 0;
    for(int z = 0; z < m; ++z){
        sum += abs(a[z]-median.first);
    }
    cout << sum << " ";
    auto prevMedian = median;
    i = 1;
    ++j;
    while(j < n){       
        S.erase({a[i-1],i-1});
        int size = S.size();
        int tmp;
        S.insert({a[j],j});
        median = *S.find_by_order(mid);
        S.erase({a[j],j});
        if(median.first > prevMedian.first){
            tmp = S.order_of_key({prevMedian.first+1,-1});
        }else if(median.first < prevMedian.first){
            tmp = S.order_of_key({prevMedian.first,-1});
        }
        S.insert({a[j],j});
        sum = sum - abs(a[i-1]-prevMedian.first) + abs(a[j]-median.first);
        if(prevMedian.first == median.first){
            cout << sum << " ";
        }else{
            if(median.first > prevMedian.first){
                sum += tmp*(median.first-prevMedian.first);
                sum = sum - (size-tmp)*(median.first-prevMedian.first);
            }else{  
                sum = sum - (tmp)*(prevMedian.first - median.first);
                sum += (size-tmp)*(prevMedian.first - median.first);
            }
            cout << sum << " ";
        }   
        prevMedian = median;
        ++i;
        ++j;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    solve();
}


