#include "bits/stdc++.h"

#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
#endif

using namespace std;
#define int long long

bool change_string (string& s, string& sub, map <string, string>& mp) {
    bool changed = false;
    string res;
    int n = (int) s.size();
    int m = (int) sub.size();
    vector <bool> marked (n, false);
    for (int i = 0; i < n; i++) {
        if (marked[i]) continue;
        bool found = true;
        bool reached_end = false;
        for (int j = 0; j < m && i + m - 1 < n; j++) {
            if (s[i + j] != sub[j]) {
                found = false;
            }
            if (j == m - 1) {
                reached_end = true;
            }
        }
        if (!found || !reached_end) {
            res += s[i];
        } else {
            res += mp[sub];
            for (int j = 0; j < m; j++) {
                marked[i + j] = true;
            }
            changed = true;
        }
    }
    // debug (sub);
    // debug (res);
    s = res;
    return changed;
}

void testcase() {
    int n;
    scanf("%lld", &n);
    string s;
    cin >> s;
    vector <string> sub = {"01", "12", "23", "34", "45", "56", "67", "78", "89", "90"};
    map <string, string> mp = {{"01", "2"}, {"12", "3"}, {"23", "4"}, {"34", "5"}, {"45", "6"}, {"56", "7"}, {"67", "8"}, {"78", "9"}, {"89", "0"}, {"90", "1"}};
    bool done = false;
    do {
        done = false;
        for (auto temp: sub) {
            // debug (s);
            done |= change_string(s, temp, mp);
        }
    } while (done);
    cout << s;
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



