#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int d, n, x;
    scanf("%lld%lld%lld", &d, &n, &x);
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        int q, l, v;
        scanf("%lld%lld%lld", &q, &l, &v);
        a[i] = {l, v, q};
    }
    sort(a.begin(), a.end());
    priority_queue<pair<int, int>> pq;
    int ind = 0;
    int ans = 0;
    for (int day = d - 1; day >= 0; day--) {
        while (ind < n && d - a[ind][0] - 1 >= day) {
            pq.push({a[ind][1], a[ind][2]});
            ind++;
        }
        int rem = x;
        while (rem > 0 && (int)pq.size() > 0) {
            pair<int, int> cur = pq.top();
            int take = min(rem, cur.second);
            ans += cur.first * take;
            rem -= take;
            cur.second -= take;
            pq.pop();
            if (cur.second > 0) {
                pq.push(cur);
            }
        }
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
