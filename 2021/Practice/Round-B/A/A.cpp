#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

void testcase() {
    int n;
    scanf("%lld", &n);
    string s;
    cin >> s;
    // int ans = 0;
    char p = 0;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] > p) {
            cur++;
        } else {
            cur = 1;
        }
        p = s[i];
        // ans = max (cur, ans);
        printf("%lld ", cur);
    }
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
