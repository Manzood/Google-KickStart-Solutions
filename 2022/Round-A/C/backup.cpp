#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long
constexpr int mod = (int)1e9 + 7;

bool checkpalindrome(string& s, int start, int end) {
    int n = end - start + 1;
    for (int i = 0; i < n / 2; i++) {
        if (s[start + i] != s[start + n - i - 1]) {
            // debug (s);
            return false;
        }
    }
    return true;
}

bool check(string& s) {
    int n = s.size();
    bool not_pal = true;
    for (int i = 0; i < n; i++) {
        for (int j = i + 4; j < n; j++) {
            if (checkpalindrome(s, i, j)) {
                // debug (s);
                not_pal = false;
            }
        }
    }
    return not_pal;
}

bool recursive(string& s, int index) {
    int n = s.size();
    if (index == n) {
        return check(s);
    }
    bool retval = false;
    if (s[index] == '?') {
        s[index] = '0';
        retval |= recursive(s, index + 1);
        s[index] = '1';
        retval |= recursive(s, index + 1);
        s[index] = '?';
    } else {
        retval |= recursive(s, index + 1);
    }
    return retval;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    string s;
    cin >> s;
    bool ans = recursive(s, 0);
    ans ? printf("POSSIBLE") : printf("IMPOSSIBLE");
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
