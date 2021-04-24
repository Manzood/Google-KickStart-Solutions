#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

const int inf = (int) 1e9 + 7;

void testcase () {
    int n;
    scanf("%lld", &n);
    vector <int> a(n);
    int diff = inf;
    vector <int> left(n, 1), right(n, 1);
    vector <int> leftdiff(n, inf), rightdiff(n, inf);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (i > 0) {
            if (a[i] - a[i-1] == diff) {
                left[i] = left[i-1] + 1;
            } else {
                left[i] = 2;
                diff = a[i] - a[i-1];
            }
            leftdiff[i] = a[i] - a[i-1];
        }
    }
    diff = inf;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] - a[i+1] == diff) {
            right[i] = right[i+1] + 1;
        } else {
            right[i] = 2;
            diff = a[i] - a[i+1];
        }
        rightdiff[i] = a[i] - a[i+1];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i + 2 < n) {
            if (rightdiff[i+2] == leftdiff[i]) {
                ans = max (ans, right[i+2] + left[i] + 1);
            } else {
                ans = max (ans, max (right[i+2], left[i+1]) + 1);
            }
        }
        if (i + 1 < n) {
            ans = max (ans, right[i+1] + 1);
        }
    }
    // for (int i = 0; i < n; i++) {
        // printf("%lld ", left[i]);
    // }
    // printf("\n");
    // for (int i = 0; i < n; i++) {
        // printf("%lld ", right[i]);
    // }
    // printf("\n");
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
