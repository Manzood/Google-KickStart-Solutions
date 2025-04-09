#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

bool is_palindrome(string& s) {
    int n = (int)s.size();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) return false;
    }
    return true;
}

void fill_pos(string& cur, vector<vector<string>>& dp, int index,
              int dp_index) {
    if (index == (int)cur.size()) {
        dp[dp_index].push_back(cur);
        return;
    }
    if (cur[index] == '?') {
        cur[index] = '0';
        fill_pos(cur, dp, index + 1, dp_index);
        cur[index] = '1';
        fill_pos(cur, dp, index + 1, dp_index);
        cur[index] = '?';
    } else {
        fill_pos(cur, dp, index + 1, dp_index);
    }
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    string s;
    cin >> s;
    vector<vector<string>> dp(n);
    // fill dp[3]
    if (n > 4) {
        string cur = s.substr(0, 4);
        fill_pos(cur, dp, 0, 3);
    }
    for (int i = 4; i < n; i++) {
        for (auto p : dp[i - 1]) {
            string cur = p;
            cur += s[i];
            if ((int)cur.size() > 6) cur = cur.substr((int)cur.size() - 6, 6);
            int len = (int)cur.size();
            if (cur[len - 1] == '?') {
                if ((int)cur.size() == 5) {
                    cur[len - 1] = '0';
                    if (!is_palindrome(cur)) dp[i].push_back(cur);
                    cur[len - 1] = '1';
                    if (!is_palindrome(cur)) dp[i].push_back(cur);
                } else {
                    cur[len - 1] = '0';
                    string tmp;
                    if (!is_palindrome(cur) &&
                        !is_palindrome(tmp = cur.substr(0, 5)) &&
                        !is_palindrome(tmp = cur.substr(1, 5)))
                        dp[i].push_back(cur);
                    cur[len - 1] = '1';
                    if (!is_palindrome(cur) &&
                        !is_palindrome(tmp = cur.substr(0, 5)) &&
                        !is_palindrome(tmp = cur.substr(1, 5)))
                        dp[i].push_back(cur);
                }
            } else {
                if ((int)cur.size() == 5) {
                    if (!is_palindrome(cur)) dp[i].push_back(cur);
                } else {
                    string tmp;
                    if (!is_palindrome(cur) &&
                        !is_palindrome(tmp = cur.substr(0, 5)) &&
                        !is_palindrome(tmp = cur.substr(1, 5)))
                        dp[i].push_back(cur);
                }
            }
        }
    }
    bool ans = n <= 4 || (int)dp[n - 1].size();
    printf(ans ? "POSSIBLE" : "IMPOSSIBLE");
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
