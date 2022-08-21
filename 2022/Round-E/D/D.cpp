#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
// right, left, down, up
bool ok(vector<int> temp, int n, int m) {
    int x = temp[0];
    int y = temp[1];
    return x >= 0 && y >= 0 && x < n && y < m;
}

vector<int> get_pos(vector<int> pos, vector<int> dir) {
    pos[0] += dir[0];
    pos[1] += dir[1];
    return pos;
}

int f(int c, pair<char, int>& d, int units) {
    if (d.first == '+') {
        return c + (d.second * units);
    } else if (d.first == '*') {
        int val = c;
        for (int i = 0; i < units; i++) {
            val *= d.second;
        }
        return val;
    } else if (d.first == '/') {
        int val = c;
        for (int i = 0; i < units; i++) {
            c /= d.second;
        }
        return val;
    } else {
        return c - (d.second * units);
    }
}

void get_ans_from_pos(vector<int>& pos, map<pair<char, int>, vector<int>>& mp,
                      int temp, int n, pair<char, int> up, pair<char, int> down,
                      pair<char, int> right, pair<char, int> left, int m,
                      int& val, int& ans) {
    int best_op = 0;
    if (ok(get_pos(pos, mp[right]), n, n)) {
        temp = f(temp, right, 1);
        temp = f(temp, left, 1);
    }
    best_op = max(best_op, temp);
    temp = 0;
    if (ok(get_pos(pos, mp[left]), n, n)) {
        temp = f(temp, left, 1);
        temp = f(temp, right, 1);
    }
    best_op = max(best_op, temp);
    temp = 0;
    if (ok(get_pos(pos, mp[down]), n, n)) {
        temp = f(temp, down, 1);
        temp = f(temp, up, 1);
    }
    best_op = max(best_op, temp);
    temp = 0;
    if (ok(get_pos(pos, mp[up]), n, n)) {
        temp = f(temp, up, 1);
        temp = f(temp, down, 1);
    }
    best_op = max(best_op, temp);
    while (m > 1) {
        // check up, down, left, right, make the best set of moves;
        val += best_op;
        ans = max(ans, val);
        m -= 2;
    }
    int rem = m & 1;
    if (rem) {
        int t = val;
        if (ok(get_pos(pos, mp[right]), n, n)) {
            t = max(t, f(t, right, 1));
        }
        t = val;
        if (ok(get_pos(pos, mp[down]), n, n)) {
            t = max(t, f(t, down, 1));
        }
        t = val;
        if (ok(get_pos(pos, mp[up]), n, n)) {
            t = max(t, f(t, up, 1));
        }
        t = val;
        if (ok(get_pos(pos, mp[left]), n, n)) {
            t = max(t, f(t, left, 1));
        }
        val = max(val, t);
    }
    ans = max(ans, val);
}

void spam_dir(vector<int>& pos, int val, int n, int m,
              map<pair<char, int>, vector<int>>& mp, pair<char, int>& dir) {
    val = 0;
    while (ok(get_pos(pos, mp[dir]), n, n) && m) {
        val = f(val, dir, 1);
        pos = get_pos(pos, mp[dir]);
        m--;
    }
}

void solve([[maybe_unused]] int test) {
    int n, p, m, a_x, a_y;
    scanf("%lld%lld%lld%lld%lld", &n, &p, &m, &a_x, &a_y);
    vector<pair<char, int>> d(4);
    for (int i = 0; i < 4; i++) {
        cin >> d[i].first;
        scanf("%lld", &d[i].second);
    }
    vector<int> x(p), y(p), c(p);
    for (int i = 0; i < p; i++) {
        scanf("%lld%lld%lld", &x[i], &y[i], &c[i]);
    }
    pair<char, int> up = d[0], right = d[1], left = d[2], down = d[3];
    map<pair<char, int>, vector<int>> mp;
    mp[up] = dirs[3];
    mp[down] = dirs[2];
    mp[left] = dirs[1];
    mp[right] = dirs[0];
    int ans = 0;

    // approach #1
    // if (n > 1) {
    //     int val = 0;
    //     for (int i = 0; i < m; i++) {
    //         if (i & 1) {
    //             // go up
    //             val = f(val, up, 1);
    //         } else {
    //             // go down
    //             val = f(val, down, 1);
    //         }
    //     }
    //     ans = max(ans, val);
    //     val = 0;
    //     for (int i = 0; i < m; i++) {
    //         if (i & 1) {
    //             // go left
    //             val = f(val, left, 1);
    //         } else {
    //             // go right
    //             val = f(val, right, 1);
    //         }
    //     }
    //     ans = max(ans, val);
    // }
    // if (n > 2 && m >= 2) {
    //     int val = 0;
    //     val = f(val, down, 1);
    //     val = f(val, right, 1);
    //     int temp = val;
    //     val = 0;
    //     val = f(val, right, 1);
    //     val = f(val, down, 1);
    //     val = max(temp, val);
    //     // now to get the best op
    //     int best_op = 0;
    //     temp = 0;
    //     temp = f(temp, right, 1);
    //     temp = f(temp, left, 1);
    //     best_op = max(best_op, temp);
    //     temp = 0;
    //     temp = f(temp, left, 1);
    //     temp = f(temp, right, 1);
    //     best_op = max(best_op, temp);
    //     temp = 0;
    //     temp = f(temp, down, 1);
    //     temp = f(temp, up, 1);
    //     best_op = max(best_op, temp);
    //     temp = 0;
    //     temp = f(temp, up, 1);
    //     temp = f(temp, down, 1);
    //     best_op = max(best_op, temp);
    //     val += best_op * ((m - 2) / 2);
    //     int rem = m & 1;
    //     if (rem) {
    //         val = max(val, f(val, right, 1));
    //         val = max(val, f(val, down, 1));
    //         val = max(val, f(val, up, 1));
    //         val = max(val, f(val, left, 1));
    //     }
    //     ans = max(ans, val);
    // }

    // approach #2
    vector<int> pos = {a_x, a_y};
    int val = 0;
    int temp = val;
    get_ans_from_pos(pos, mp, temp, n, up, down, right, left, m, val, ans);

    // spam up
    pos = {a_x, a_y};
    val = 0;
    temp = val;
    while (ok(get_pos(pos, mp[up]), n, n) && m) {
        val = f(val, up, 1);
        pos = get_pos(pos, mp[up]);
        m--;
    }
    get_ans_from_pos(pos, mp, temp, n, up, down, right, left, m, val, ans);
    // up then right
    pos = {a_x, a_y};
    val = 0;
    temp = val;
    while (ok(get_pos(pos, mp[up]), n, n) && m) {
        val = f(val, up, 1);
        pos = get_pos(pos, mp[up]);
        m--;
    }
    spam_dir(pos, val, n, m, mp, right);
    get_ans_from_pos(pos, mp, temp, n, up, down, right, left, m, val, ans);
    // up then left
    pos = {a_x, a_y};
    val = 0;
    temp = val;
    while (ok(get_pos(pos, mp[up]), n, n) && m) {
        val = f(val, up, 1);
        pos = get_pos(pos, mp[up]);
        m--;
    }
    spam_dir(pos, val, n, m, mp, left);
    get_ans_from_pos(pos, mp, temp, n, up, down, right, left, m, val, ans);

    // spam down
    pos = {a_x, a_y};
    val = 0;
    temp = val;
    while (ok(get_pos(pos, mp[down]), n, n) && m) {
        val = f(val, down, 1);
        pos = get_pos(pos, mp[down]);
        m--;
    }
    get_ans_from_pos(pos, mp, temp, n, up, down, right, left, m, val, ans);
    // spam down then left
    pos = {a_x, a_y};
    val = 0;
    temp = val;
    while (ok(get_pos(pos, mp[down]), n, n) && m) {
        val = f(val, down, 1);
        pos = get_pos(pos, mp[down]);
        m--;
    }
    spam_dir(pos, val, n, m, mp, left);
    get_ans_from_pos(pos, mp, temp, n, up, down, right, left, m, val, ans);
    // spam down then right
    pos = {a_x, a_y};
    val = 0;
    temp = val;
    while (ok(get_pos(pos, mp[down]), n, n) && m) {
        val = f(val, down, 1);
        pos = get_pos(pos, mp[down]);
        m--;
    }
    spam_dir(pos, val, n, m, mp, right);
    get_ans_from_pos(pos, mp, temp, n, up, down, right, left, m, val, ans);

    // spam right
    pos = {a_x, a_y};
    val = 0;
    temp = val;
    while (ok(get_pos(pos, mp[right]), n, n) && m) {
        val = f(val, right, 1);
        pos = get_pos(pos, mp[right]);
        m--;
    }
    get_ans_from_pos(pos, mp, temp, n, up, down, right, left, m, val, ans);
    // right then up
    pos = {a_x, a_y};
    val = 0;
    temp = val;
    while (ok(get_pos(pos, mp[right]), n, n) && m) {
        val = f(val, right, 1);
        pos = get_pos(pos, mp[right]);
        m--;
    }
    spam_dir(pos, val, n, m, mp, up);
    get_ans_from_pos(pos, mp, temp, n, up, down, right, left, m, val, ans);
    // right then down
    pos = {a_x, a_y};
    val = 0;
    temp = val;
    while (ok(get_pos(pos, mp[right]), n, n) && m) {
        val = f(val, right, 1);
        pos = get_pos(pos, mp[right]);
        m--;
    }
    spam_dir(pos, val, n, m, mp, down);
    get_ans_from_pos(pos, mp, temp, n, up, down, right, left, m, val, ans);

    // spam left
    pos = {a_x, a_y};
    val = 0;
    temp = val;
    while (ok(get_pos(pos, mp[left]), n, n) && m) {
        val = f(val, left, 1);
        pos = get_pos(pos, mp[left]);
        m--;
    }
    get_ans_from_pos(pos, mp, temp, n, up, down, right, left, m, val, ans);
    // left then up
    pos = {a_x, a_y};
    val = 0;
    temp = val;
    while (ok(get_pos(pos, mp[left]), n, n) && m) {
        val = f(val, left, 1);
        pos = get_pos(pos, mp[left]);
        m--;
    }
    spam_dir(pos, val, n, m, mp, up);
    get_ans_from_pos(pos, mp, temp, n, up, down, right, left, m, val, ans);
    // left then down
    pos = {a_x, a_y};
    val = 0;
    temp = val;
    while (ok(get_pos(pos, mp[left]), n, n) && m) {
        val = f(val, left, 1);
        pos = get_pos(pos, mp[left]);
        m--;
    }
    spam_dir(pos, val, n, m, mp, down);
    get_ans_from_pos(pos, mp, temp, n, up, down, right, left, m, val, ans);

    for (int i = 0; i < (1LL << m); i++) {
    }
    printf("%lld", ans);
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
