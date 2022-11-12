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
    vector<int> dp(n + 1);
    iota(dp.begin(), dp.end(), 0);
    for (int i = 2; i <= n; i++) {
        int cost = dp[i] + 6;
        for (int j = i + i; j <= n; j += i) {
            dp[j] = min(dp[j], cost);
            cost += 2;
        }
        if (i + 1 <= n) dp[i + 1] = min(dp[i + 1], dp[i] + 1);
    }
    // for (int i = 1; i <= n; i++) {
    //     dp[i] = min(dp[i], dp[i - 1] + 1);
    // }
    // debug(dp);
    printf("%lld", dp[n]);
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
