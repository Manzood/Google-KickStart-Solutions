#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

bool isPalindrome(string s) {
    int n = (int)s.size();
    /* if (n < 5) return false; // might wanna remove this one */
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) return false;
    }
    return true;
}

int statesVisited = 0;
int helper(string prev, int index, string& s, map<pair<int, string>, int>& dp) {
    if (index == (int)s.size()) return 1;
    if (dp.find({index, prev}) != dp.end()) {
        debug(index, prev);
        return dp[{index, prev}];
    }
    statesVisited++;
    string x1 = prev.substr(1, 4) + '0';
    string x2 = prev.substr(1, 4) + '1';
    int ans = 0;
    if (s[index] == '?') {
        if (!isPalindrome(x1) && !isPalindrome(prev + "0"))
            ans += helper(x1, index + 1, s, dp);
        if (!isPalindrome(x2) && !isPalindrome(prev + "1"))
            ans += helper(x2, index + 1, s, dp);
    } else if (s[index] == '1') {
        if (!isPalindrome(x2) && !isPalindrome(prev + '1'))
            ans += helper(x2, index + 1, s, dp);
    } else {
        if (!isPalindrome(x1) && !isPalindrome(prev + '0'))
            ans += helper(x1, index + 1, s, dp);
    }
    return dp[{index, prev}] = ans;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    string s;
    cin >> s;
    map<pair<int, string>, int> dp;
    cout << (helper("?????", 0, s, dp) ? "POSSIBLE" : "IMPOSSIBLE");
}

int32_t main() {
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        printf("Case #%lld: ", tt);
        solve(tt);
        printf("\n");
    }
    cout << statesVisited << "\n";
}
