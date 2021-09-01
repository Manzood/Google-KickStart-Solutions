#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

void solve () {
    int n;
    scanf("%lld", &n);
    if (n < 10000) {
        vector <double> sum(n + 1, 0);
        vector <double> e(n + 1, 0);

        for (int i = n; i >= 1; i--) {
            if (i == n) {
                e[i] = 1.0f;
                sum[i] = e[i];
            } else {
                float cnt = n - i + 1;
                e[i] = sum[i + 1] / cnt;
                e[i] += 1.0f;
                sum[i] = sum[i + 1] + e[i];
            }
        }

        printf("%f", e[1]);
    } else {
        // approximate it
        double gamma = 0.5772156649;
        double LOG = log(n);
        double ans = LOG + gamma;
        long double M = n;
        ans += (1 / (2 * M)) - (1 / (12 * M * M)) - (1 / (120 * M * M * M * M));
        printf("%f", ans);
    }
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
