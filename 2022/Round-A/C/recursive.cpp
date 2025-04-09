#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

bool isPalindrome(string s) {
    string temp = s;
    reverse(temp.begin(), temp.end());
    return temp == s;
}

int statesVisited = 0;
int helper(string prev, int index, string& s) {
    if (index == (int)s.size()) return 1;
    statesVisited++;
    string x = prev.substr(1, 4);
    int ans = 0;
    if (s[index] == '0') {
        if (!isPalindrome(x + '0') && !isPalindrome(prev + '0')) {
            ans += helper(x + '0', index + 1, s);
        }
    } else if (s[index] == '1') {
        if (!isPalindrome(x + '1') && !isPalindrome(prev + '1')) {
            ans += helper(x + '1', index + 1, s);
        }
    } else {
        if (!isPalindrome(x + '0') && !isPalindrome(prev + '0')) {
            ans += helper(x + '0', index + 1, s);
        }
        if (!isPalindrome(x + '1') && !isPalindrome(prev + '1')) {
            ans += helper(x + '1', index + 1, s);
        }
    }
    return ans;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    string s;
    cin >> s;
    cout << (helper("?????", 0, s) ? "POSSIBLE" : "IMPOSSIBLE");
}

int32_t main() {
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        printf("Case #%lld: ", tt);
        solve(tt);
        printf("\n");
    }
    cout << statesVisited << "\n";
}
