#include "bits/stdc++.h"

#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
#endif

using namespace std;
#define int long long

void testcase() {
    int n;
    scanf("%lld", &n);
    string s;
    cin >> s;

    vector <int> prev(n, -1);
    vector <int> next(n, -1);
    iota (prev.begin(), prev.end(), -1);
    iota (next.begin(), next.end() - 1, 1);
    // debug (prev);

    vector <vector <int>> loc(10);
    for (int i = 0; i < n - 1; i++) {
        if (s[i + 1] == s[i] + 1 || (s[i] == '9' && s[i+1] == '0')) {
            loc[s[i] - '0'].push_back(i);
        }
    }

    // debug (loc);

    // repeat while operations keep happening
    bool done = false;
    vector <bool> deleted(n, false);

    while (!done) {
        done = true;

        for (int i = 0; i < 10; i++) {
            vector <int> temp = loc[i];
            loc[i].clear();
            for (auto ind: temp) {
                if (deleted[ind]) continue;
                bool continuing = false;
                if (s[next[ind]] == s[ind] + 1 || (s[ind] == '9' && s[next[ind]] == '0')) {
                    continuing = true;
                }
                if (!continuing) continue;

                done = false;
                // delete next one, replace this one
                if (next[next[ind]] != -1) {
                    prev[next[next[ind]]] = ind;
                }

                deleted[next[ind]] = true;
                next[ind] = next[next[ind]];
                s[ind] += 2;
                if (s[ind] == '9' + 1) s[ind] = '0';
                if (s[ind] == '9' + 2) s[ind] = '1';

                // check condition for next and previous
                if (s[next[ind]] == s[ind] + 1 || (s[ind] == '9' && s[next[ind]] == '0')) {
                    loc[s[ind] - '0'].push_back (ind);
                }
                if (s[ind] == s[prev[ind]] + 1 || (s[prev[ind]] == '9' && s[ind] == '0')) {
                    loc[s[prev[ind]] - '0'].push_back (prev[ind]);
                }
            }
        }
    }

    // debug (deleted);

    int ind = -1;
    for (int i = 0; i < n; i++) {
        if (!deleted[i]) {
            ind = i;
            break;
        }
    }

    string ans;
    while (ind != -1) {
        ans += s[ind];
        ind = next[ind];
    }

    cout << ans;
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
