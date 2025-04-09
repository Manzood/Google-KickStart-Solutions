#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

bool checkpalindrome(string& s) {
    int n = (int)s.size();
    assert(n == 6);
    bool six = true;
    for (int i = 0; i < n / 2; i++)
        if (s[i] != s[n - 1 - i]) six = false;
    bool ffive = true, sfive = true;
    for (int i = 0; i < (n - 1) / 2; i++)
        if (s[i] != s[n - 2 - i]) ffive = false;
    for (int i = 0; i < (n - 1) / 2; i++)
        if (s[i + 1] != s[n - 1 - i]) sfive = false;
    return (six | ffive | sfive);
}

bool check(string s) {
    bool retval = true;
    vector<string> possibilities;
    // lambda function to generate strings
    function<void(int)> getpossibilities = [&](int ind) {
        if (ind == 5) {
            possibilities.push_back(s);
            return;
        }
        if (s[ind] == '?') {
            s[ind] = '0';
            getpossibilities(ind + 1);
            s[ind] = '1';
            getpossibilities(ind + 1);
            s[ind] = '?';
        } else {
            getpossibilities(ind + 1);
        }
    };
    for (auto x : possibilities) {
        retval &= checkpalindrome(x);
    }
    return retval;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    string s;
    cin >> s;
    bool ans = false;
    for (int i = 5; i < n; i++) {
        string cur = s.substr(i - 5, 6);
        ans |= check(cur);
    }
    printf(ans ? "IMPOSSIBLE" : "POSSIBLE");
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
