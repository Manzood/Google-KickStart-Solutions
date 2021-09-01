#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

// solving for k = 1

void solve () {
    int R, C, K;
    scanf("%lld%lld%lld", &R, &C, &K);
    int r1, c1, r2, c2;
    scanf("%lld%lld%lld%lld", &r1, &c1, &r2, &c2);

    int necessary = 0;
    necessary = min ({r1 - 1, c1 - 1, R - r2, C - c2});
    int r = r2 - r1 + 2; // number of rows to cut
    int c = c2 - c1 + 2; // number of columns to curt

    int ans = 0;
    ans += r * (c2 - c1 + 1);
    ans += c * (r2 - r1 + 1);
    ans += necessary;

    if (r1 == 1) {
        ans -= (c2 - c1 + 1);
    }
    if (r2 == R) {
        ans -= (c2 - c1 + 1);
    }
    if (c1 == 1) {
        ans -= (r2 - r1 + 1);
    }
    if (c2 == C) {
        ans -= (r2 - r1 + 1);
    }

    printf("%lld", ans);
}

int32_t main () {
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        printf("Case #%lld: ", tt);
        solve();
        printf("\n");
    }
}
