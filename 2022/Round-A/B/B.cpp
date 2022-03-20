#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long
constexpr int mod = (int) 1e9 + 7;

void solve([[maybe_unused]] int test) {
    // int n;
    // scanf("%lld", &n);
    string num;
    cin >> num;
    int sum = 0;
    // int m = n;
    vector <int> number;
    // while (m) {
    for (int i = 0; i < (int) num.size(); i++) {
        sum += num[i] - '0';
        number.push_back(num[i] - '0');
    }
    int digit = 9 - (sum % 9);
    // reverse(number.begin(), number.end());
    vector <int> ans;
    if (digit != 9) {
        int i = 0;
        for (i = 0; i < (int) number.size() && number[i] <= digit; i++) {
            ans.push_back(number[i]);
        }
        ans.push_back(digit);
        while (i < (int) number.size()) {
            ans.push_back(number[i++]);
        }
    } else {
        ans.push_back(number[0]);
        ans.push_back(0);
        for (int i = 1; i < (int) number.size(); i++) {
            ans.push_back(number[i]);
        }
    }
    for (int i = 0; i < (int) ans.size(); i++) {
        printf("%lld", ans[i]);
    }
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
