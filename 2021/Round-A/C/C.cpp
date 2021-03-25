#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

void testcase () {
    int r, c;
    scanf("%lld%lld", &r, &c);
    vector <vector <int>> a(r);
    for (int i = 0; i < r; i++) {
        a[i].resize(c);
        for (int j = 0; j < c; j++) {
            scanf("%lld", &a[i][j]);
        }
    }
    int ans = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 1; j < c; j++) {
            if (a[i][j] < a[i][j-1] - 1) {
                ans += a[i][j-1] - a[i][j] - 1;
                a[i][j] = a[i][j-1] - 1;
            }
        }
        for (int j = c - 2; j >= 0; j--) {
            if (a[i][j] < a[i][j+1] - 1) {
                ans += a[i][j+1] - a[i][j] - 1;
                a[i][j] = a[i][j+1] - 1;
            }
        }
    }
    for (int i = 1; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i][j] < a[i-1][j] - 1) {
                ans += a[i-1][j] - 1 - a[i][j];
                a[i][j] = a[i-1][j] - 1;
            }
        }
    }
    for (int i = r - 2; i >= 0; i--) {
        for (int j = 0; j < c; j++) {
            if (a[i][j] < a[i+1][j] - 1) {
                ans += a[i+1][j] - 1 - a[i][j];
                a[i][j] = a[i+1][j] - 1;
            }
        }
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
