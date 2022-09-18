#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, k, x, d;
    scanf("%lld%lld%lld%lld", &n, &k, &x, &d);
    int m;
    scanf("%lld", &m);
    vector<vector<pair<int, int>>> a(n);
    for (int i = 0; i < m; i++) {
        int p, l, r;
        scanf("%lld%lld%lld", &p, &l, &r);
        a[p - 1].push_back({l, r});
    }
    int ans = (int)1e9 + 7;
    for (int i = x; i <= d; i++) {
        vector<int> cnt(n, 0);
        int start = i - x;
        int end = i;
        for (int j = 0; j < n; j++) {
            for (auto meeting : a[j]) {
                // if ((meeting.first >= start && meeting.second <= end) ||
                //     (meeting.first <= start && meeting.second > start) ||
                //     (meeting.first < end && meeting.second >= end)) {
                if (!((meeting.first <= start && meeting.second <= start) ||
                      (meeting.first >= end && meeting.second >= end))) {
                    cnt[j]++;
                }
            }
        }
        sort(cnt.begin(), cnt.end());
        int cur = 0;
        for (int j = 0; j < k; j++) {
            cur += cnt[j];
        }
        ans = min(ans, cur);
    }
    printf("%lld", ans);
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
