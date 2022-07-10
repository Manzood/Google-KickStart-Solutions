#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    sort(a.begin(), a.end());
    float ans = 0;
    if (n == m) {
        ans = sum;
    } else {
        for (int i = 0; i < n; i++) {
            // this is the outlier
            float val = sum - a[i];
            if (i == 0) {
                val -= a[1];
                val += (float)a[1] / 2.0f;
            } else {
                val -= a[0];
                val += (float)a[0] / 2.0f;
            }
            val += (float)a[i] / 2.0f;
            ans = max(ans, val);
        }
    }
    debug(n, m);
    debug(sum, ans);
    printf("%f", ans);
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
