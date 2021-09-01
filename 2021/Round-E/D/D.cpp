#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

double ans = 0;
void permute(vector <int> a, int l, int r, double prob) {
    if (l == r) {
        int card = a[0];
        int tot = 1;
        for (int i = 1; i < (int) a.size(); i++) {
            if (a[i] > card) {
                tot++;
                card = a[i];
            }
        }
        ans += prob * (double) tot;

        // for (int i = 0; i < (int) a.size(); i++) {
            // printf("%lld ", a[i]);
        // }
        // printf("\n");
    } else {
        // Permutations made
        for (int i = l; i <= r; i++) {
            swap(a[l], a[i]);
            permute(a, l+1, r, prob);
            swap(a[l], a[i]);
        }
    }
}

void solve () {
    int n;
    scanf("%lld", &n);
    ans = 0;
    double prob = 1.0f;
    for (int i = 0; i < n; i++) {
        double cur = 1.0f / (double) (n - i);
        prob *= cur;
    }

    vector <int> a(n);
    iota (a.begin(), a.end(), 1);
    permute (a, 0, (int)a.size() - 1, prob);

    printf("%lf", ans);
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
