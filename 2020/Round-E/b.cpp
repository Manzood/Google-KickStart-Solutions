#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

void testcase() {
    int n, a, b, c;
    scanf("%d%d%d%d", &n, &a, &b, &c);
    vector <int> ans(n);
    bool possible = true;
    a -= c;
    b -= c;
    int aval = 1;
    int bval = n-1;
    // print filler before if b == 0
    if (a < 0 || b < 0 || c < 1) possible = false;
    if (a + b + c > n) possible = false;
    for (int i = 0; i < n; i++) {
        if (a == 0 && b == 0)  {
            if (n > 1 && c < 2) possible = false;
            if (i < c-1) {
                ans[i] = n;
            }
            else if (i != n-1) {
                ans[i] = 1;
            }
            else {
                ans[i] = n;
            }
        }
        else if (b == 0) {
            if (i < a) {
                if (n - a - c > 0 && a == 1) aval = 2;
                ans[i] = aval++;
            }
            else if (n-i > c) {
                ans[i] = 1;
            }
            else {
                ans[i] = n;
            }
        }
        else {
            if (i < a) {
                ans[i] = aval++;
            }
            else if (i < a+c) {
                ans[i] = n;
            }
            else if (n - i > b) {
                ans[i] = 1;
            }
            else {
                ans[i] = bval--;
            }
        }
    }
    if (possible) {
        for (int i = 0; i < n; i++) {
            printf("%d ", ans[i]);
        }
    } 
    else {
        printf("IMPOSSIBLE");
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