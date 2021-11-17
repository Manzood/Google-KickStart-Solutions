#include "bits/stdc++.h"

#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
#endif

using namespace std;
#define int long long

void testcase() {
    string s, f;
    cin >> s >> f;
    int ans = 0;
    for (int i = 0; i < (int) s.size(); i++) {
        int dist = (int) 1e9+7;
        for (auto x: f) {
            dist = min (dist, (int) min (abs (x - s[i]), 26 - abs (x - s[i])) );
        }
        ans += dist;
    }
    printf("%lld", ans);
}

int32_t main () {
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        printf("Case #%lld: ", tt);
        testcase();
        printf("\n");
    }
}
