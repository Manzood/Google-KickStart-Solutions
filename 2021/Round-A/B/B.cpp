#include "bits/stdc++.h"
using namespace std;
#define int long long

vector<string> vec_splitter(string s) {
    s += ','; vector<string> res;
    while(!s.empty()) {
        res.push_back(s.substr(0, s.find(',')));
        s = s.substr(s.find(',') + 1);
    }
    return res;
}
void debug_out( vector<string> __attribute__ ((unused)) args, __attribute__ ((unused)) int idx, __attribute__ ((unused)) int LINE_NUM) { cerr << endl; } template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
    if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
    stringstream ss; ss << H;
    cerr << args[idx] << " = " << ss.str();
    debug_out(args, idx + 1, LINE_NUM, T...);
}
#ifdef local
    #define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
    #define debug(...) 42
#endif

void testcase () {
    int r, c;
    scanf("%lld%lld", &r, &c);
    vector <vector <int>> a(r);
    vector <vector <int>> up(r), down(r), left(r), right(r);
    for (int i = 0; i < r; i++) {
        a[i].resize(c); up[i].resize(c); down[i].resize(c); left[i].resize(c); right[i].resize(c);
        for (int j = 0; j < c; j++) {
            scanf("%lld", &a[i][j]);
            if (a[i][j] == 1) {
                if (i > 0) up[i][j] = up[i-1][j] + 1;
                else up[i][j] = 1;
                if (j > 0) left[i][j] = left[i][j-1] + 1;
                else left[i][j] = 1;
            } else {
                up[i][j] = 0;
                left[i][j] = 0;
            }
        }
    }
    for (int i = r - 1; i >= 0; i--) {
        for (int j = c - 1; j >= 0; j--) {
            if (a[i][j] == 1) {
                if (i < r - 1) down[i][j] = down[i+1][j] + 1;
                else down[i][j] = 1;
                if (j < c - 1) right[i][j] = right[i][j+1] + 1;
                else right[i][j] = 1;
            } else {
                down[i][j] = 0;
                right[i][j] = 0;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            // if (up[i][j] > 1) {
                // if (right[i][j] > 1) {
                    // if (up[i][j] >= 2 * right[i][j]) {
                        // ans += up[i][j] / 2 - right[i][j] + 1;
                        // debug(i, j);
                    // }
                    // if (right[i][j] >= 2 * up[i][j]) {
                        // ans += right[i][j] / 2 - up[i][j] + 1;
                        // debug(i, j);
                    // }
                // }
                // if (left[i][j] > 1) {
                    // if (up[i][j] >= 2 * left[i][j]) {
                        // ans += up[i][j] / 2 - left[i][j] + 1;
                        // debug(i, j);
                    // }
                    // if (left[i][j] >= 2 * up[i][j]) {
                        // ans += left[i][j] / 2 - up[i][j] + 1;
                        // debug(i, j);
                    // }
                // }
            // }
            // if (down[i][j] > 1) {
                // if (right[i][j] > 1) {
                    // if (down[i][j] >= 2 * right[i][j]) {
                        // ans += down[i][j] / 2 - right[i][j] + 1;
                        // debug(i, j);
                    // }
                    // if (right[i][j] >= 2 * down[i][j]) {
                        // ans += right[i][j] / 2 - down[i][j] + 1;
                        // debug(i, j);
                    // }
                // }
                // if (left[i][j] > 1) {
                    // if (down[i][j] >= 2 * left[i][j]) {
                        // ans += down[i][j] / 2 - left[i][j] + 1;
                        // debug(i, j);
                    // }
                    // if (left[i][j] >= 2 * down[i][j]) {
                        // ans += left[i][j] / 2 - down[i][j] + 1;
                        // debug(i, j);
                    // }
                // }
            // }

            ans += max(min(up[i][j] / 2, right[i][j]) - 1, 0LL);
            ans += max(min(right[i][j] / 2, up[i][j]) - 1, 0LL);

            ans += max(min(up[i][j] / 2, left[i][j]) - 1, 0LL);
            ans += max(min(left[i][j] / 2, up[i][j]) - 1, 0LL);

            ans += max(min(down[i][j] / 2, right[i][j]) - 1, 0LL);
            ans += max(min(right[i][j] / 2, down[i][j]) - 1, 0LL);

            ans += max(min(down[i][j] / 2, left[i][j]) - 1, 0LL);
            ans += max(min(left[i][j] / 2, down[i][j]) - 1, 0LL);
        }
    }
    // printf("\n");
    // for (int i = 0; i < r; i++) {
        // for (int j = 0; j < c; j++) {
            // printf("%lld ", right[i][j]);
        // }
        // printf("\n");
    // }
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
