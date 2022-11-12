#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector<bool> visited;
vector<int> dp;

int dfs(int node, vector<vector<int>>& adj, vector<int>& a) {
    int retval = 1;
    if (visited[node]) return dp[node];
    visited[node] = true;
    for (auto u : adj[node]) {
        if (a[u] < a[node]) {
            retval += dfs(u, adj, a);
        }
    }
    return dp[node] = retval;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (auto& x : a) {
        scanf("%lld", &x);
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%lld%lld", &x, &y);
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    visited.assign(n, false);
    dp.assign(n, 0);
    for (int i = 0; i < n; i++) {
        dfs(i, adj, a);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
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
