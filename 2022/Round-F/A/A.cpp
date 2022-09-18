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
    vector<pair<string, int>> c(n);
    vector<pair<int, int>> d(n);
    for (int i = 0; i < n; i++) {
        int u;
        cin >> c[i].first;
        scanf("%lld%lld", &d[i].first, &u);
        c[i].second = u;
        d[i].second = u;
    }
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += c[i].second == d[i].second;
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
