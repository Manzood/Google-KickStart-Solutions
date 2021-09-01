#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

void solve () {
    int e, n;
    scanf("%lld%lld", &e, &n);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    int start = 0, end = n - 1;
    sort (a.begin(), a.end());

    int honor = 0;

    while (start <= end) {
        if (e > a[start]) {
            e -= a[start++];
            honor++;
        } else if (start != end && e + a[end] > a[start]) {
            e += a[end--];
            honor--;
        } else {
            start++;
        }
    }

    printf("%lld", honor);
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
