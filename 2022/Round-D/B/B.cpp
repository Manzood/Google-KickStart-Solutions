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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int m;
    scanf("%lld", &m);
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        scanf("%lld", &b[i]);
    }
    int k;
    scanf("%lld", &k);
    vector<int> Apref(n, 0), Asuff(n, 0);
    vector<int> Bpref(m, 0), Bsuff(m, 0);
    for (int i = 0; i < n; i++) {
        Apref[i] += a[i];
        if (i > 0) Apref[i] += Apref[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        Asuff[i] += a[i];
        if (i < n - 1) Asuff[i] += Asuff[i + 1];
    }
    for (int i = 0; i < m; i++) {
        Bpref[i] += b[i];
        if (i > 0) Bpref[i] += Bpref[i - 1];
    }
    for (int i = m - 1; i >= 0; i--) {
        Bsuff[i] += b[i];
        if (i < m - 1) Bsuff[i] += Bsuff[i + 1];
    }

    vector<int> Abest(k + 1, 0), Bbest(k + 1, 0);
    for (int i = 1; i <= k; i++) {
        if (i > n) break;
        int best = 0;
        for (int j = 0; j <= i; j++) {
            int cur = 0;
            if (j > 0) cur += Apref[j - 1];
            int rem = i - j;
            if (rem > 0) cur += Asuff[n - rem];
            best = max(best, cur);
        }
        Abest[i] = best;
    }
    for (int i = 1; i <= k; i++) {
        if (i > m) break;
        int best = 0;
        for (int j = 0; j <= i; j++) {
            int cur = 0;
            if (j > 0) cur += Bpref[j - 1];
            int rem = i - j;
            if (rem > 0) cur += Bsuff[m - rem];
            best = max(best, cur);
        }
        Bbest[i] = best;
    }
    int ans = 0;
    for (int i = 0; i <= k; i++) {
        int val = Abest[i] + Bbest[k - i];
        ans = max(ans, val);
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
