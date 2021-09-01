#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

const int MAX_N = 1e4 + 5;

void solve () {
    int n, c;
    scanf("%lld%lld", &n, &c);
    vector <int> L(n), R(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &L[i], &R[i]);
    }

    vector <int> range (MAX_N, 0);
    // sort (L.begin(), L.end());
    // sort (R.begin(), R.end());

    for (int i = 0; i < n; i++) {
        range[L[i] + 1]++;
        range[R[i]]--;
    }

    int val = 0;
    for (int i = 0; i < MAX_N; i++) {
        val += range[i];
        range[i] = val;
    }

    // for (int i = 0; i < 15; i++) {
        // printf("%lld ", range[i]);
    // }
    // printf("\n");

    sort (range.begin(), range.end());

    int ans = n;
    for (int i = MAX_N - 1; i >= 0; i--) {
        if (c == 0) break;
        ans += range[i];
        c--;
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
