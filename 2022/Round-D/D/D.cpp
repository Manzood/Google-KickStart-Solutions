#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    vector<int> a(m), b(m);
    vector<bool> guilty(n, true);
    for (int i = 0; i < m; i++) {
        scanf("%lld%lld", &a[i], &b[i]);
        guilty[b[i] - 1] = false;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (guilty[i] == false) ans++;
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
