#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int l, n;
    scanf("%lld%lld", &l, &n);
    vector<int> a(n);
    vector<char> c(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %c", &a[i], &c[i]);
    }
    int pos = 0;
    int dir = 1;
    int prev_dir = 1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        dir = c[i] == 'C' ? 1 : 0;
        if (i == 0) prev_dir = dir;
        int rounds = 0;
        bool crossed = false;
        if (dir == 1) {
            int req = l - pos;
            crossed = a[i] >= req;
            if (pos != 0 && dir != prev_dir) req = 2 * l - pos;
            pos += a[i];
            if (a[i] >= req) {
                crossed = true;
                a[i] -= req;
                rounds++;
                rounds += (pos + a[i]) / l;
            }
            pos %= l;
        } else {
            int req = -pos;
            crossed = -a[i] <= req;
            pos -= a[i];
            if (test == 2 && i == 2) debug(req, prev_dir, req);
            if (prev_dir != dir) a[i] += req;
            if (a[i] >= 0) rounds = (a[i] - pos) / l;
            pos %= l;
            if (pos < 0) pos += l;
        }
        rounds = max(rounds, 0LL);
        ans += rounds;
        if (crossed) prev_dir = dir;
        if (test == 2) debug(i, pos, rounds, crossed, prev_dir);
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
