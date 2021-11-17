#include "bits/stdc++.h"

#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
#endif

using namespace std;
#define int long long

int getans (char c, map <char, vector <char>>& d, string& s) {
    int ans = 0;
    bool found_once = false;
    for (int i = 0; i < (int) s.size(); i++) {
        char current = s[i];
        bool found = false;
        for (auto x: d[current]) {
            if (x == c) {
                found = true;
            }
        }
        if (found) {
            if (!found_once) {
                ans++;
                found_once = true;
            }
        } else {
            found_once = false;
        }
    }
    return ans;
}

void testcase() {
    int n;
    scanf("%lld", &n);
    string s;
    cin >> s;
    vector <char> primary = {'R', 'Y', 'B'};
    map <char, vector <char>> d;
    d['O'] = {'R', 'Y'};
    d['P'] = {'R', 'B'};
    d['G'] = {'B', 'Y'};
    d['A'] = {'R', 'Y', 'B'};
    d['U'] = {};
    d['R'] = {'R'};
    d['Y'] = {'Y'};
    d['B'] = {'B'};
    int ans = 0;
    for (auto c: primary) {
        ans += getans (c, d, s);
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

