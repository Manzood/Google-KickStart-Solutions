#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

void testcase () {
    int n;
    scanf("%lld", &n);
    string s;
    cin >> s;
    vector <int> left(n, (int) 1e9+7);
    vector <int> right(n, (int) 1e9+7);
    int dist = 1e9 + 7;

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') dist = 0;
        left[i] = dist;
        dist++;
    }

    dist = 1e9 + 7;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1') dist = 0;
        right[i] = dist;
        dist++;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += min (left[i], right[i]);
    }

    printf("%lld", ans);
}

int32_t main () {
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        printf("Case #%lld: ", tt);
        testcase();
        printf("\n");
    }
}
