#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(x) 42;
#endif

using namespace std;
#define int long long

constexpr int MOD = (int)1e9 + 7;
constexpr int LOG = 30;

long long inv(long long a, long long m) {
    return 1 < a ? m - inv(m % a, a) * m / a : 1;
}

int getmod(int val) {
    val %= MOD;
    if (val < 0) val += MOD;
    return val;
}

void dfs(int node, int par, vector<vector<int>>& adj, vector<int>& a,
         vector<int>& b, vector<int>& prob, vector<int>& depth) {
    if (node != 0) {
        prob[node] = (((prob[par] * a[node]) % MOD) +
                      getmod(((int)1e6 - prob[par]) * b[node])) %
                     MOD;
        depth[node] = depth[par] + 1;
    }
    for (auto u : adj[node]) {
        dfs(u, node, adj, a, b, prob, depth);
    }
}

void testcase() {
    int n, q;
    scanf("%lld%lld", &n, &q);
    vector<int> a(n, 0), b(n, 0);
    scanf("%lld\n", &a[0]);
    vector<int> p(n, -1);
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        scanf("%lld%lld%lld", &p[i], &a[i], &b[i]);
        p[i]--;
        adj[p[i]].push_back(i);
    }
    vector<int> prob(n, 0), depth(n, 0);
    dfs(0, -1, adj, a, b, prob, depth);
    vector<vector<int>> lift(n, vector<int>(LOG, -1));
    for (int i = 0; i < n; i++) lift[i][0] = p[i];
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < LOG; j++) {
            if (lift[i][j - 1] != -1) lift[i][j] = lift[lift[i][j - 1]][j - 1];
        }
    }
    for (int query = 0; query < q; query++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        int ans = (prob[u] * prob[v]) % MOD;
        if (depth[v] > depth[u]) swap(u, v);
        int dist = depth[u] - depth[v];
        for (int i = LOG - 1; i >= 0; i--) {
            if ((1LL << i) > dist) continue;
            u = lift[u][i];
            dist -= (1LL << i);
        }
        if (u == v) {
            // do something, v was an ancestor to u
        } else {
            // the answer is prob[u] * prob[v] / prob[lca]
            int lca = u;
            for (int i = LOG - 1; i >= 0; i--) {
                if (lift[u][i] == -1) continue;
                if (lift[u][i] == lift[v][i])
                    lca = lift[u][i];
                else {
                    u = lift[u][i];
                    v = lift[v][i];
                }
            }
            (ans *= inv(lca, MOD)) %= MOD;
        }
    }
}

int32_t main() {
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        printf("Case #%lld: ", tt);
        testcase();
        printf("\n");
    }
}
