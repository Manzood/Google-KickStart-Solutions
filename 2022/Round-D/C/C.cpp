#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &s[i]);
    }
    int m;
    scanf("%lld", &m);
    vector<int> k(m);
    map<int, int> get_index;
    for (int i = 0; i < m; i++) {
        scanf("%lld", &k[i]);
        get_index[k[i]] = i;
    }
    int ans = 0;
    int prev = get_index[s[0]];
    for (int i = 1; i < n; i++) {
        int ind = get_index[s[i]];
        int dist = abs(prev - ind);
        prev = ind;
        ans += dist;
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
