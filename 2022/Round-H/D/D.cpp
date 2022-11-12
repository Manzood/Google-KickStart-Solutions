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
    vector<bool> visited(n, false);
    vector<int> cycles;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            int ptr = a[i] - 1;
            int len = 1;
            while (!visited[ptr]) {
                len++;
                visited[ptr] = true;
                ptr = a[ptr] - 1;
            }
            cycles.push_back(len);
        }
    }
    sort(cycles.begin(), cycles.end());
    int num = (int)cycles.size();
    vector<int> mi(num * (num + 1) / 2 + 1, (int)1e9 + 7);
    mi[0] = -1;
    if (cycles[0] != 1)
        mi[1] = 1;
    else
        mi[1] = 0;
    for (int j = 0; j < num; j++) {
        vector<int> tmp = mi;
        for (int i = 0; i <= (num * (num + 1)) / 2; i++) {
            if (i - cycles[j] >= 0) {
                mi[i] = min(mi[i], tmp[i - cycles[j]] + 1);
            }
        }
    }
    vector<int> ans(n);
    for (int i = 1; i <= n; i++) {
        ans[i - 1] = mi[i];
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
