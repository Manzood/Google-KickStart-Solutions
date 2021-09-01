#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

void solve () {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    int tot = 0;
    bool in_countdown = false;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 1) {
            in_countdown = true;
        } else {
            if (i < n - 1) {
                if (a[i] != a[i+1] + 1) {
                    in_countdown = false;
                }
            }
        }

        if (a[i] == k && in_countdown) {
            tot++;
        }
    }

    printf("%lld", tot);
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
