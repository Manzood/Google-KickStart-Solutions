    #include<bits/stdc++.h>
    using namespace std;
    #define int long long

    void testcase() {
        int n, k;
        scanf("%lld%lld", &n, &k);
        vector <int> a(n);
        vector <int> diff(n-1);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            if (i > 0) {
                diff[i-1] = a[i] - a[i-1];
            }
        }
        make_heap(diff.begin(), diff.end());
        for (int i = 0; i < k; i++) {
            int temp = diff.front();
            if (temp == 0) break;
            pop_heap(diff.begin(), diff.end());
            diff.pop_back();
            if (temp % 2 == 0) {
                temp /= 2;
                diff.push_back(temp);
                diff.push_back(temp);
                make_heap(diff.begin(), diff.end());
            }
            else {
                temp = (temp/2) + 1;
                diff.push_back(temp);
                diff.push_back(temp-1);
                make_heap(diff.begin(), diff.end());
            }
        // for (int j = 0; j < diff.size(); j++) {
            //     cout << diff[j] << " ";
            // }
            // cout << endl;
        }
        printf("%lld", diff.front());
    }

    int32_t main() {
        int t;
        scanf("%lld", &t);
        for (int test = 1; test <= t; test++) {
            printf("Case #%lld: ", test);
            testcase();
            printf("\n");
        }
    }