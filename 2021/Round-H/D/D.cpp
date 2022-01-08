#include "bits/stdc++.h"
#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
#endif
using namespace std;
#define int long long

void testcase() {
    int n, q;
    scanf("%lld%lld", &n, &q);
    int k;
    scanf("%lld", &k);
    vector <int> parent(n, -1), a(n), b(n);
    a[0] = b[0] = -1;
    for (int i = 1; i < n; i++) {
        scanf("%lld%lld%lld", &parent[i], &a[i], &b[i]);
    }
    // recursive function to find the probability every time??
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
