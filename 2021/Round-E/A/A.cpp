#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

void solve () {
    string s, original;
    cin >> s;
    original = s;
    map <int, int> mp;
    int n = s.size();
    bool possible = true;

    for (auto x: s) {
        mp[x]++;
        if (mp[x] * 2 > n) possible = false;
    }

    // vector <bool> swapped (n, false);
    for (int i = 0; i < n; i++) {
        if (s[i] == original[i]) {
            for (int j = 0; j < n; j++) {
                if (i != j && s[i] != s[j] && original[j] != s[i]) {
                    swap (s[i], s[j]);
                    // debug (s);
                    break;
                }
            }
        }
    }

    if (possible) {
        cout << s;
    } else {
        printf("IMPOSSIBLE");
    }
}

int32_t main () {
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        printf("Case #%lld: ", tt);
        solve ();
        printf("\n");
    }
}
