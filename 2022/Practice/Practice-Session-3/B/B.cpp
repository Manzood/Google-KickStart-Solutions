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
    int cnt = 0;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        bool record_breaking = true;
        if (i > 0 && a[i] <= mx) record_breaking = false;
        if (i < n - 1 && a[i] <= a[i + 1]) record_breaking = false;
        if (record_breaking) cnt++;
        mx = max(a[i], mx);
    }
    printf("%lld", cnt);
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
