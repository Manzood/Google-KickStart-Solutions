#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

// solve it later pleb

void testcase() {
    int n;
    cin >> n;
    vector <int> a(n);
    int lowest=0, highest=0;
    int current=0;
    int ans=0;
    for (int i=0; i<n; i++) {
        // if you break the rule, go back to the ideal state
        if (i>0) {
            if (a[i] > a[i-1]) {
                current++;
            }
            else if (a[i] < a[i-1]) {
                current--;
            }
            highest = max(highest, current);
            lowest = min(lowest, current);
            if (highest - lowest >= 4) {
                ans++;
                current = 0;
                highest = 0;
                lowest = 0;
            }
            //debug(current);
            //debug(highest);
            //debug(lowest);
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