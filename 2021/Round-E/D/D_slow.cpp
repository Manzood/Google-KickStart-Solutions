#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

void solve () {
    int n;
    scanf("%lld", &n);
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
