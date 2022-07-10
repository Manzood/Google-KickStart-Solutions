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
    for (int i = n - 1; i >= n - (m - 1); i--) {
        ans += a[i];
    }
    int rem = n - (m - 1);
    if (rem & 1) {
        ans += a[rem / 2];
    } else {
        ans += (float)(a[rem / 2] + a[rem / 2 - 1]) / 2.0f;
    }
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
