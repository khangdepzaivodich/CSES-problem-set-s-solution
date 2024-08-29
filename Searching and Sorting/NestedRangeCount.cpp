#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int,int> , null_type , less<pair<int,int>> , rb_tree_tag , tree_order_statistics_node_update> orderSet;

struct Range{
    int start, end, indx;
};
bool cmp(Range r1, Range r2){
    if(r1.start == r2.start){
        return r1.end > r2.end;
    }
    return r1.start < r2.start;
}
int n;
void solve(){
    orderSet S;
    vector<Range> r(n);
    for(int i = 0; i < n; ++i){
        cin >> r[i].start >> r[i].end;
        r[i].indx = i;
    }
    sort(r.begin(),r.end(),cmp);
    int minn = r[n-1].end;
    S.insert({minn,r[n-1].indx});
    vector<int> A1(n,0), A2(n,0);
    for(int i = n-2; i >= 0; --i){
        if(r[i].end >= minn){
            A1[r[i].indx] = S.order_of_key({r[i].end+1,-1});
        }
        S.insert({r[i].end,r[i].indx});
        minn = min(minn,r[i].end);
    }
    for(int i = 0; i < n; ++i){
        cout << A1[i] << " ";
    }
    orderSet S1;
    int maxx = r[0].end;
    S1.insert({maxx,r[0].indx});
    for(int i = 1; i < n; ++i){
        if(r[i].end <= maxx){
            A2[r[i].indx] = S1.size() - S1.order_of_key({r[i].end,-1});
        }
        maxx = max(maxx,r[i].end);
        S1.insert({r[i].end,r[i].indx});
    }
    cout << '\n';
    for(int i = 0; i < n; ++i){
        cout << A2[i] << " ";   
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    solve();
}
