#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

void solve () {
    vector <vector <int>> a(3, vector <int> (3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) continue;
            scanf("%lld", &a[i][j]);
        }
    }

    int cnt = 0;
    if (a[2][0] - a[1][0] == a[1][0] - a[0][0]) cnt++;
    if (a[2][2] - a[2][1] == a[2][1] - a[2][0]) cnt++;
    if (a[0][2] - a[0][1] == a[0][1] - a[0][0]) cnt++;
    if (a[2][2] - a[1][2] == a[1][2] - a[0][2]) cnt++;
    map <int, int> tot;
    tot[a[2][2] + a[0][0]]++;
    // if (tot.count (a[2][1] + a[0][1])) rem++;
    tot[a[2][1] + a[0][1]]++;
    // if (tot.count (a[2][0] + (a[0][2]))) rem++;
    tot[a[2][0] + a[0][2]]++;
    // if (tot.count (a[1][0] + (a[1][2]))) rem++;
    tot[a[1][0] + a[1][2]]++;

    int mx = 0;
    for (auto x: tot) {
        if (x.first % 2 == 0) mx = max (mx, x.second);
    }

    cnt += mx;

    printf("%lld", cnt);
}

int32_t main () {
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        printf("Case #%lld: ", tt);
        solve();
        printf("\n");
    }
}
