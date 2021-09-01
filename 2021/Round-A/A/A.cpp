#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

void testcase() {
    int n, k;
    scanf("%lld%lld", &n, &k);
    int cnt = 0;
    string s;
    cin >> s;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            cnt++;
        }
    }
    printf("%lld", abs(cnt - k));
}

int32_t main() {
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        printf("Case #%lld: ", tt);
        testcase();
        printf("\n");
    }
}
