#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int MAX_N = 5002;

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &a[i], &b[i]);
    }
    vector<int> cnt(MAX_N, 0);
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
        cnt[b[i] + 1]--;
    }
    int val = 0;
    for (int i = 0; i < MAX_N; i++) {
        val += cnt[i];
        cnt[i] = val;
    }
    int p;
    scanf("%lld", &p);
    for (int i = 0; i < p; i++) {
        int city;
        scanf("%lld", &city);
        printf("%lld ", cnt[city]);
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
