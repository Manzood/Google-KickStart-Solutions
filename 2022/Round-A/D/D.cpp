#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long
constexpr int mod = (int) 1e9 + 7;

bool check (int num) {
    int prod = 1;
    int sum = 0;
    while (num) {
        int digit = num % 10;
        prod *= digit;
        sum += digit;
        num /= 10;
    }
    return (prod % sum == 0);
}

void solve([[maybe_unused]] int test) {
    int a, b;
    scanf("%lld%lld", &a, &b);
    int ans = 0;
    for (int i = a; i <= b; i++) {
        if (check(i)) ans++;
    }
    printf("%lld", ans);
}

int32_t main() {
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        printf("Case #%lld: ", tt);
        solve(tt);
        printf("\n");
    }
}
