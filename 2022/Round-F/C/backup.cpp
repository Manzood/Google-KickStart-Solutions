#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int d, n, x;
    scanf("%lld%lld%lld", &d, &n, &x);
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        int q, l, v;
        scanf("%lld%lld%lld", &q, &l, &v);
        a[i] = {v, l, q};
    }
    // sort(a.begin(), a.end());
    vector<int> day(d, 0);
    for (int i = 0; i < n; i++) {
        int cur = d - a[i][1] - 1;
        int val = a[i][0];
        while (cur >= 0 && day[cur] != 0) {
            if (val > day[cur]) {
                swap(val, day[cur]);
            }
            cur--;
        }
        if (cur >= 0) {
            day[cur] = val;
        }
    }
    int ans = 0;
    for (int i = 0; i < d; i++) {
        ans += day[i];
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
