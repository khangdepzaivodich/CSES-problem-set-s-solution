#include<bits/stdc++.h>
using namespace std;

int n,m;
void solve(){
    vector<int> v(n);
    vector<int> pos(n+1);   
    int bound = 0;
    for(int i = 0; i < n; ++i){
        cin >> v[i];
        pos[v[i]] = i;
        bound = max(bound,v[i]);
    }
    int ans = 1;
    int x,k;
    cin >> x >> k;
    swap(pos[v[x-1]],pos[v[k-1]]);
    swap(v[x-1],v[k-1]);
    for(int i = 1; i < n; ++i){         
        if(pos[i] > pos[i+1]){
            ++ans;
        }
    }
    cout << ans << '\n';
    --m;
    while(m--){
        cin >> x >> k;
        if(x == k){
            cout << ans << '\n';
            continue;
        }
        int maxx = max(v[x-1],v[k-1]);
        int other = v[x-1] != maxx ? v[x-1] : v[k-1];
        if(abs(v[x-1]-v[k-1]) == 1){            
            if(maxx + 1 <= bound){
                if(pos[maxx+1] < pos[maxx]){
                    if(pos[other] < pos[maxx+1]){
                        --ans;
                    }
                    }else{
                        if(pos[maxx+1] < pos[other]){
                            ++ans;  
                        }
                    }
                }
            if(pos[other] < pos[maxx]){
                ++ans;
            }else{
                --ans;
            }
            if(other != 1){
                if(pos[other-1] < pos[other]){
                    if(pos[other-1] > pos[maxx]){
                        ++ans;
                    }
                }else{
                    if(pos[other-1] < pos[maxx]){
                        --ans;
                    }
                }
            }
        }else{
            if(maxx + 1 <= bound){
                if(pos[maxx+1] < pos[maxx]){
                    if(pos[maxx+1] > pos[other]){
                        --ans;
                    }
                }else{
                    if(pos[maxx+1] < pos[other]){
                        ++ans;
                    }
                }
            }
            if(pos[maxx-1] < pos[maxx]){
                if(pos[maxx-1] > pos[other]){
                    ++ans;
                }
            }else{
                if(pos[maxx-1] < pos[other]){
                    --ans;
                }
            }
            if(pos[other+1] < pos[other]){
                if(pos[other+1] > pos[maxx]){
                    --ans;
                }
            }else{
                if(pos[other+1] < pos[maxx]){
                    ++ans;
                }
            }
            if(other != 1){
                if(pos[other-1] < pos[other]){
                    if(pos[other-1] > pos[maxx]){
                        ++ans;
                    }
                }else{
                    if(pos[other-1] < pos[maxx]){
                        --ans;
                    }
                }
            }
        }
        cout << ans << '\n';
        swap(pos[maxx],pos[other]);
        swap(v[x-1],v[k-1]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    solve();
}


