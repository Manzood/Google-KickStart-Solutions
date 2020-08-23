#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

void testcase() {
    int n;
    scanf("%d", &n);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int ans = 2;
    int curr = 2;
    int diff = 0;
    diff = a[1] - a[0];
    for (int i = 2; i < n; i++) {
        if (a[i] - a[i-1] == diff) {
            curr++;
        }
        else {
            diff = a[i] - a[i-1];
            curr = 2;
        }
        ans = max(curr, ans);
    }
    printf("%d", ans);   
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