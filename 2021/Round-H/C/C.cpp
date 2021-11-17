#include "bits/stdc++.h"

#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
#endif

using namespace std;
#define int long long

bool change_string (string& s, string sub, map <string, string>& mp) {
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
    map <char, char> prev_char = {{'0', '9'}, {'1', '0'}, {'2', '1'}, {'3', '2'}, {'4', '3'}, {'5', '4'}, {'6', '5'}, {'7', '6'}, {'8', '7'}, {'9', '8'}};
    map <char, char> next_char;
    for (auto x: prev_char) {
        next_char[x.second] = x.first;
    }
    map <string, string> mp = {{"01", "2"}, {"12", "3"}, {"23", "4"}, {"34", "5"}, {"45", "6"}, {"56", "7"}, {"67", "8"}, {"78", "9"}, {"89", "0"}, {"90", "1"}};
    change_string (s, "01", mp);
    n = s.size();
    string temp;
    temp += s[0];
    for (int i = 1; i < n; i++) {
        int x = (int) temp.size() - 1;
        while (x >= 0 && temp[x] == prev_char[s[i]]) {
            temp.pop_back();
            s[i] = next_char[s[i]];
            x--;
        }
    }
    cout << temp;
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


