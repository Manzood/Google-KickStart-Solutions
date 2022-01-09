#include "bits/stdc++.h"
#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
#endif
using namespace std;
#define int long long
const int mod = (int) 1e9 + 7;

// problem seems to have far too many parts, maybe I'll come back to it later when I've learnt how to use the individual techniques

// algorithm
// precompute the values for all nodes, without conditions
// find lca for the two nodes -- binary lifting?
// get the value for the nodes
// store the value in the answer array after taking modular inverse? Or something of the sort

// I'll solve the lca problem myself

int getpow(int a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    if (b % 2 == 0) {
        int t = getpow(a, b / 2);
        return (t * t) % mod;
    } else {
        int t = getpow(a, (b - 1) / 2);
        return (((a * t) % mod) * t) % mod;
    }
}

// (a / b) % MOD = a * ((b ^ (MOD - 2)) % MOD; // ONLY if MOD is prime
int divide(int a, int b) { return a * getpow(b, mod - 2) % mod; }

// now, find lca (currently using binary lifting)
int lca (int a, int b) {
    int retval = 0;
    // gotta think of how this works
    // O(log(n) * log(n))
    // binary search values, twice
    // go through parent array, and binary search it
    return retval;
}

// dfs assigns the probablity of occurance of each individual node
vector <bool> visited;
void dfs (int node, vector <vector <int>>& adj, vector <int>& parent, vector <int>& prob, vector <int>& prob_not, vector <int>& a, vector <int>& b) {
    if (visited[node]) return;
    visited[node] = true;
    // get the value of parent
    if (node != 0) {
        prob[node] = prob[parent[node]] * a[node] + prob_not[parent[node]] * b[node];
        // convert to inverse_mod
        // can you take modulo if you have inverse mod?
        prob_not[node] = 1000000 - prob[node];
    }
    for (auto u: adj[node]) {
        dfs (u, adj, parent, prob, prob_not, a, b);
    }
}

void testcase() {
    int n, q;
    scanf("%lld%lld", &n, &q);
    int k;
    scanf("%lld", &k);
    vector <int> parent(n, 0LL), a(n), b(n);
    vector <vector <int>> adj (n);
    visited.resize (n, false);
    a[0] = b[0] = -1;
    vector <int> prob (n, -1);
    vector <int> prob_not (n, -1);
    prob[0] = k;
    prob_not[0] = 1000000 - k;
    for (int i = 1; i < n; i++) {
        scanf("%lld%lld%lld", &parent[i], &a[i], &b[i]);
        adj[parent[i]].push_back (i);
    }

    // convert it into modular inverse, and keep using that for each intermediate step as well
    // recursive function to find the probability every time??
}

int32_t main () {
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        printf("Case #%lld: ", tt);
        testcase();
        printf("\n");
    }
}
