#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 2e5 + 5;
ll tree[4 * MAXN], lazy[4 * MAXN];
int n, q;

void build(vector<ll>& V, int si, int st, int se) {
    if(st == se) {
        tree[si] = V[st];
    } else {
        int mid = (st + se) / 2;
        build(V, 2 * si, st, mid);
        build(V, 2 * si + 1, mid + 1, se);
        tree[si] = tree[2 * si] + tree[2 * si + 1];
    }
}

void updateRange(int si, int st, int se, int l, int r, ll val) {
    if(lazy[si] != 0) {
        tree[si] += (se - st + 1) * lazy[si];
        if(st != se) {
            lazy[2 * si] += lazy[si];
            lazy[2 * si + 1] += lazy[si];
        }
        lazy[si] = 0;
    }
    if(st > se || st > r || se < l) return;

    if(st >= l && se <= r) {
        tree[si] += (se - st + 1) * val;
        if(st != se) {
            lazy[2 * si] += val;
            lazy[2 * si + 1] += val;
        }
        return;
    }
    int mid = (st + se) / 2;
    updateRange(2 * si, st, mid, l, r, val);
    updateRange(2 * si + 1, mid + 1, se, l, r, val);
    tree[si] = tree[2 * si] + tree[2 * si + 1];
}

ll query(int si, int st, int se, int idx) {
    if(st > se || st > idx || se < idx) return 0;

    if(lazy[si] != 0) {
        tree[si] += (se - st + 1) * lazy[si];
        if(st != se) {
            lazy[2 * si] += lazy[si];
            lazy[2 * si + 1] += lazy[si];
        }
        lazy[si] = 0;
    }
    if(st == se) {
        return tree[si];
    }
    int mid = (st + se) / 2;
    if(idx <= mid) {
        return query(2 * si, st, mid, idx);
    } else {
        return query(2 * si + 1, mid + 1, se, idx);
    }
}

void solve() {
    cin >> n >> q;
    vector<ll> V(n);
    for(auto &i : V) cin >> i;

    build(V, 1, 0, n - 1);

    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            updateRange(1, 0, n - 1, a - 1, b - 1, u);
        } else {
            int p;
            cin >> p;
            cout << query(1, 0, n - 1, p - 1) << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
