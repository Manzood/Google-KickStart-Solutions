#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector<int> z_function(string& s) {
    int n = (int)s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}

// bool is_palindrome(string& s) {
//     int n = (int)s.size();
//     for (int i = 0; i < n / 2; i++) {
//         if (s[i] != s[n - i - 1]) {
//             return false;
//         }
//     }
//     return true;
// }

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    string p;
    cin >> p;
    string q;
    vector<bool> is_palindrome(n, false);
    vector<bool> is_palindrome_reverse(n, false);

    string temp = p;
    string rev = p;
    reverse(rev.begin(), rev.end());
    temp += rev;
    vector<int> vals = z_function(temp);
    int m = vals.size();
    for (int i = 0; i < (int)m; i++) {
        int val = vals[i];
        if (val > 0 && i + val - 1 == m - 1 && val <= n) {
            is_palindrome[val - 1] = true;
        }
    }

    temp = p;
    reverse(temp.begin(), temp.end());
    rev = p;
    reverse(rev.begin(), rev.end());
    temp += rev;
    vals = z_function(temp);
    m = vals.size();
    for (int i = 0; i < (int)m; i++) {
        int val = vals[i];
        if (val > 0 && i + val - 1 == m - 1 && val <= n) {
            is_palindrome_reverse[n - val] = true;
        }
    }

    for (int i = 0; i < n; i++) {
        if (is_palindrome[i] && (i == n - 1 || is_palindrome_reverse[i + 1])) {
            for (int j = 0; j <= i; j++) {
                q += p[j];
            }
            break;
        }
    }

    cout << q;
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
