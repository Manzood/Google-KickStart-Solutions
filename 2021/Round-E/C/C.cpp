#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

vector <bool> visited;
int ans = 0;

void dfs (int node, vector <vector <int>>& adj, vector <string>& a) {
    visited[node] = true;
    for (auto u: adj[node]) {
        // debug (u);
        // copy to the main array
        int n = a[0].size();
        int i = u / n;
        int j = u % n;
        // debug (i);
        // debug (j);
        int nodei = node / n;
        int nodej = node % n;
        if (a[i][j] == '.') {
            ans++;
        }
        a[i][j] = a[nodei][nodej];
        // now visit it
        if (!visited[u]) {
            dfs (u, adj, a);
        }
    }
}

void solve () {
    int n, m;
    scanf("%lld%lld", &n, &m);
    ans = 0;
    vector <string> a(n);
    vector <vector <int>> vertl(n, vector <int> (m, 0));
    vector <vector <int>> horl(n, vector <int> (m, 0));
    vector <vector <int>> distup(n, vector <int> (m, 0));
    vector <vector <int>> distleft(n, vector <int> (m, 0));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    visited.resize (n * m, false);
    for (int i = 0; i < n * m; i++) {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != '#') {
                if (j > 0) {
                    horl[i][j] = horl[i][j-1] + 1;
                } else {
                    horl[i][j] = 1;
                }
                distleft[i][j] = horl[i][j];
                if (j == m - 1 || a[i][j + 1] == '#') {
                    int temp = j - 1;
                    while (temp >= 0 && a[i][temp] != '#') {
                        horl[i][temp] = horl[i][j];
                        temp--;
                    }
                }

                if (i > 0) {
                    vertl[i][j] = vertl[i-1][j] + 1;
                } else {
                    vertl[i][j] = 1;
                }
                distup[i][j] = vertl[i][j];
                if (i == n - 1 || a[i + 1][j] == '#') {
                    int temp = i - 1;
                    while (temp >= 0 && a[temp][j] != '#') {
                        vertl[temp][j] = vertl[i][j];
                        temp--;
                    }
                }
            }
        }
    }

    // printf("\n");
    // for (int i = 0; i < n; i++) {
        // for (int j = 0; j < m; j++) {
            // printf("%lld ", vertl[i][j]);
        // }
        // printf("\n");
    // }
    // printf("\n");
    // for (int i = 0; i < n; i++) {
        // for (int j = 0; j < m; j++) {
            // printf("%lld ", horl[i][j]);
        // }
        // printf("\n");
    // }

    // make graph
    vector <vector <int>> adj (n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // find the two connnections here
            if (a[i][j] != '#') {
                if (horl[i][j] > 1) {
                    // find horizontal index
                    int ind = horl[i][j] - distleft[i][j];
                    if (ind + 1 != distleft[i][j]) {
                        // not centered
                        ind = j - distleft[i][j] + 1 + ind;
                        // make connection with a[i][ind]
                        int connectionindex = m * i + ind;
                        adj[m * i + j].push_back(connectionindex);
                    }
                }
                if (vertl[i][j] > 1) {
                    // find vertical index
                    int ind = vertl[i][j] - distup[i][j];
                    if (ind + 1 != distup[i][j]) {
                        // not centered
                        ind = i - distup[i][j] + 1 + ind;
                        // make connection with a[i][ind]
                        int connectionindex = m * ind + j;
                        adj[m * i + j].push_back(connectionindex);
                        // debug (ind);
                        // debug (j);
                    }
                }
            }
        }
    }
    // graph has been made

    // printing graph
    // for (int i = 0; i < n; i++) {
        // for (int j = 0; j < m; j++) {
            // printf("%lld, %lld: ", i, j);
            // for (int k = 0; k < (int) adj[i * m + j].size(); k++) {
                // printf("%lld = %lld %lld, ", adj[i * m + j][k], adj[i * m + j][k] / m, adj[i * m + j][k] % m);
            // }
            // printf("\n");
        // }
    // }

    // now dfs
    // printf("printed\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int node = i * m + j;
            // debug (node);
            if (!visited[node] && a[i][j] != '#' && a[i][j] != '.') {
                dfs (node, adj, a);
            }
        }
    }

    printf("%lld\n", ans);
    for (int i = 0; i < n; i++) {
        cout << a[i] << "\n";
    }
}

int32_t main () {
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        printf("Case #%lld: ", tt);
        solve();
        // printf("\n");
    }
}
