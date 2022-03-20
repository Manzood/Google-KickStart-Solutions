#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    string s, t;
    cin >> s >> t;
    int sptr = 0, tptr = 0;
    int n = s.size(), m = t.size();
    while (sptr < n && tptr < m) {
        if (s[sptr] == t[tptr]) sptr++;
        tptr++;
    }
    bool possible = false;
    if (sptr == n) {
        possible = true;
    }
    if (possible) {
        printf("%lld\n", m - n);
    } else {
        printf("IMPOSSIBLE\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        printf("Case #%lld: ", tt);
        solve(tt);
    }
}
