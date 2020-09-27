#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

void solve() {
    // incredibly stupid bug, if I'm honest with myself. 
    // Note to future self: check even the basic if conditions, you somehow manage to mess even those up when you're sleepy.
    // finally solved it, made a logical mistake as well. Actually, two of them. Think clearly for every problem, do not underestimate any of them.
    int n, k;
    scanf("%d%d", &n, &k);
    vector <pair<int, int>> time(n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &time[i].first, &time[i].second);
    }
    sort(time.begin(), time.end());
    int end = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (end <= time[i].second) {
            int div = (time[i].second - max(time[i].first, end)) / (k);
            if ((time[i].second - max(time[i].first, end)) % k > 0) div++;
            end = max(time[i].first, end) + (k * div);
            ans += (div);
        }
    }
    printf("%d", ans);
}

int main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        printf("Case #%d: ", tt);
        solve();
        printf("\n");
    }
}