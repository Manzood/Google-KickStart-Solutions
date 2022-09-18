#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void dfs(int node, int cur, vector<vector<int>>& adj, vector<int>& level,
         vector<bool>& visited) {
    if (visited[node]) return;
    visited[node] = true;
    level[node] = cur;
    for (auto u : adj[node]) {
        dfs(u, cur + 1, adj, level, visited);
    }
}

void solve([[maybe_unused]] int test) {
    int n, q;
    scanf("%lld%lld", &n, &q);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // do a simple dfs to calculate the level of each node
    vector<int> level(n, -1);
    vector<bool> visited(n, false);
    dfs(0, 0, adj, level, visited);
    vector<int> count(n, 0);
    for (int i = 0; i < n; i++) {
        count[level[i]]++;
    }
    int ans = 0;
    int cur = 0;
    int rem = count[cur];
    for (int i = 0; i < q; i++) {
        int query;
        scanf("%lld", &query);
        // queries are meant to be ignored??
        rem--;
        if (rem == 0) {
            ans += count[cur];
            cur++;
            rem = count[cur];
        }
    }
    printf("%lld", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        printf("Case #%lld: ", tt);
        solve(tt);
        printf("\n");
    }
}
