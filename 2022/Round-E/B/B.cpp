#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<vector<int>> copy(n);
    for (int i = 0; i < n; i++) {
        copy[i] = {a[i], i};
    }
    sort(copy.begin(), copy.end());
    vector<int> b(n), index(n);
    for (int i = 0; i < n; i++) {
        b[i] = copy[i][0];
        index[i] = copy[i][1];
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int ind = upper_bound(b.begin(), b.end(), 2 * a[i]) - b.begin();
        if (ind > 0 && index[ind - 1] == i) {
            ind--;
        }
        if (ind > 0) {
            ans[i] = b[ind - 1];
        } else {
            ans[i] = -1;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%lld ", ans[i]);
    }
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
