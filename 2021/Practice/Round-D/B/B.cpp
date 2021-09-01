#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

const int MAX_N = 1e4 + 5;

void solve () {
    int n, c;
    scanf("%lld%lld", &n, &c);
    vector <int> L(n), R(n);
    map <int, int> mp;
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &L[i], &R[i]);
        mp[L[i]]++;
        mp[R[i]]--;
    }
    vector <int> A(n + 1, 0);
    int val = 0;
    int p = -1;
    for (auto x: mp) {
        val += x.second;
        if (p != -1) A[val] += x.first - p;
        p = x.first;
    }

    sort (A.begin(), A.end());

    int i = n;
    int ans = 0;
    while (c > 0 && i >= 0) {
        int cnt = min (A[i], c);
        ans += i * cnt;
        c -= cnt;
        i--;
    }

    printf("%lld\n", ans);
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
