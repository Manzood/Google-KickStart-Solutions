#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

// find the largest building
// do a bfs from there, and make consecutive buildings at least a[i] - 1;
// do not change it to a[i] or anything, obviously
// continue from there in all four directions

// make multiple passes until the grid follows the rules?

// make a big change
// and then multiple smaller changes

int ans = 0;

bool is_okay (int i, int j, int n, int m) {
    if (i < 0 || j < 0 || i >= n || j >= m) {
        return false;
    }
    return true;
}

vector <pair <int, int>> pts = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector <vector <bool>> visited;
set <pair <int, int>> visits;

void bfs (int i, int j, vector <vector <int>>& a) {
    visited[i][j] = true;
    for (auto p : pts) {
        if (is_okay(i + p.first, j + p.second, a.size(), a[i].size())) {
            if (a[i + p.first][j + p.second] < a[i][j] - 1) {
                ans += a[i][j] - 1 - a[i + p.first][j + p.second];
                a[i + p.first][j + p.second] = a[i][j] - 1;
            }
        }
    }
    for (auto p: pts) {
        if (is_okay(i + p.first, j + p.second, a.size(), a[i].size())) {
            if (!visited[i + p.first][ j + p.second]) {
                bfs(i + p.first, j + p.second, a);
            }
        }
    }
}

void bfs2 (int i, int j, vector <vector <int>>& a) {
    // if (i < j) visits.insert({i, j});
    // else visits.insert({j, i});
    visits.insert({i, j});
    bool made_change = false;
    for (auto p : pts) {
        if (is_okay(i + p.first, j + p.second, a.size(), a[i].size())) {
            if (a[i + p.first][j + p.second] < a[i][j] - 1) {
                ans += a[i][j] - 1 - a[i + p.first][j + p.second];
                a[i + p.first][j + p.second] = a[i][j] - 1;
                made_change = true;
            }
        }
    }
    if (!made_change) return;
    for (auto p: pts) {
        if (is_okay(i + p.first, j + p.second, a.size(), a[i].size())) {
            // if (visits.count({min(i + p.first, j + p.second), max(i + p.first, j + p.second)}) == 0) {
            if (visits.count({i, j}) == 0) {
                bfs2(i + p.first, j + p.second, a);
            }
        }
    }
}

void testcase () {
    ans = 0;
    int r, c;
    scanf("%lld%lld", &r, &c);
    visited.resize(r);
    vector <vector <int>> a(r);
    int m = 0;
    int mx = 0;
    int my = 0;
    for (int i = 0; i < r; i++) {
        a[i].resize(c);
        visited[i].resize(c, false);
        for (int j = 0; j < c; j++) {
            scanf("%lld", &a[i][j]);
            if (a[i][j] > m) {
                mx = i;
                my = j;
                m = a[i][j];
            }
        }
    }
    // bfs(mx, my, a);
    // for (int i = 0; i < r; i++) {
        // for (int j = 0; j < c; j++) {
            // visited[i][j] = false;
        // }
    // }
    // first big change complete, continue with the grid
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            bfs(i, j, a);
            for (int ti = 0; ti < r; ti++) {
                for (int tj = 0; tj < c; tj++) {
                    visited[i][j] = false;
                }
            }
        }
    }
    // for (int i = 0; i < r; i++) {
        // for (int j = 0; j < c; j++) {
            // printf("%lld ", a[i][j]);
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

