#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

void testcase() {
    int n;
    scanf("%d", &n);
    vector <pair<int, int> > a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].first, &a[i].second);
        sum += a[i].first;
    }
    set <int> removed;
    bool found = false;
    int count = 0;
    int csum = 0;
    int ans = 0;
    bool indefinite = false;
    int i = 0;
    int remans = 0;
    while (!found) {
        if (i == n) {
            i = 0;
            count++;
        }
        if (count == 0) {
            csum += a[i].first;
            ans = max(csum, ans);
            i++;
            continue;
        }
        if (sz(removed) == n) {
            break;
        }
        if (count == 2) {
            indefinite = true;
            found = true;
            break;
        }
        if (removed.count(i)) {
            i++;
            continue;
        }
        if (a[i].second > sum - a[i].first) {
            removed.insert(i);
            i = 0;
            csum = 0;
            count = 0;
            sum -= a[i].first;
            continue;
        }
        csum += a[i].first;
        i++;
        if (ans < csum) {
            ans = csum;
            remans = sz(removed);
        }
    }
    if (indefinite == true) {
        printf("%d INDEFINITELY", (int)removed.size());
    }
    else {
        printf("%d %d", remans, ans);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int test = 1; test <= t; test++) {
        printf("Case #%d: ", test);
        testcase();
        printf("\n");
    }
}