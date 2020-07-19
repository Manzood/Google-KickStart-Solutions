#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

void testcase() {
    int n;
    scanf("%d", &n);
    vector <int> a(n);
    int max = -1;
    int ans = 0;
    int maxind = -1;
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        if (i>0 && a[i] < a[i-1] && maxind == i-1) 
            ans++;
        if (i == n-1) {
            if (a[i] > max) ans++;
        }
        if (a[i] > max) {
            max = a[i];
            maxind = i;
        }
    }
    printf("%d", ans);
}

int main() {
    int t;
    cin >> t;
    for (int test=1; test<=t; test++) {
        printf("Case #%d: ", test);
        testcase();
        printf("\n");
    }
}