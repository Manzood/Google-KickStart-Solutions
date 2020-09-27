#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;

bool compare (pair<int, int> a, pair<int, int> b) {
    if (a.second > b.second) return false;
    return true;
}

void solve() {
    int n, x;
    scanf("%d%d", &n, &x);
    vector <int> a(n);
    vector <pair<int, int>> ans(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        // storing the number of moves first, index second
        ans[i].first = a[i]/x;
        ans[i].first += (a[i] % x == 0 ? 0 : 1);
        ans[i].second = i+1;
    }
    sort(ans.begin(), ans.end()); 
    int start = 0;
    int end = 0;
    for (int i = 0; i < n; i++) {
        if (ans[i] == ans[start]) {
            end = i;
        }
        else {
            sort(ans.begin()+start, ans.begin()+end, compare);
            start = i+1;
            end = i+1;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i].second);
    }
}

int main() {
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        printf("Case #%d: ", tt);
        solve();
        printf("\n");
    }
}
