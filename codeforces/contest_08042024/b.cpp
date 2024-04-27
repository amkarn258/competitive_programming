#include <bits/stdc++.h>
#define ll long long int
 
using namespace std;
 
bool dfs(vector<vector<char>>& grid, map<pair<pair<int, int>, int>, int>& visited, int i, int j, int moves) {
    if (i==1 && j==grid[0].size()-1) {
        return true;
    }
    if (i<0 || j<0 || i>=2 || j>=grid[0].size()) return false;
    if (visited.find({{i, j}, moves%2})!=visited.end()) {
        return visited[{{i, j}, moves%2}];
    }
    vector<pair<int, int>> neighbors;
    neighbors.push_back({1, 0});
    neighbors.push_back({0, 1});
    neighbors.push_back({-1, 0});
    neighbors.push_back({0, -1});
    bool ans = false;
    visited[{{i, j}, moves%2}] = ans;
    if (moves%2==0) {
        for (auto x: neighbors) {
            ans |= dfs(grid, visited, i + x.first, j + x.second, moves + 1);
            if (ans) return visited[{{i, j}, moves%2}] = true;
        }
    }
    else {
        if (grid[i][j]=='<') {
            ans |= dfs(grid, visited, i, j-1, moves + 1);
        }
        else if (grid[i][j]=='>') {
            ans |= dfs(grid, visited, i, j + 1, moves + 1);
        }
        if (ans) return visited[{{i, j}, moves%2}] = true;
    }
    return visited[{{i, j}, moves%2}] = ans;
}
 
int main() {
    ll t;
    cin>>t;
    while (t--) {
        ll n, c, d;
        cin>>n>>c>>d;
        vector<int> a;
        for (ll i=0; i<n*n; i++) {
            ll x;
            cin>>x;
            a.push_back(x);
        }
        sort(a.begin(), a.end());
        vector<vector<int>> dp(n, vector<int>(n, -1));
        dp[0][0] = a[0];
        vector<int> vals;
        // vals.push_back(a[0]);
        for (ll i=1; i<n; i++) {
            dp[i][0] = dp[i-1][0] + c;
            // vals.push_back(dp[i])
        }
        for (ll i=0; i<n; i++) {
            for (ll j=1; j<n; j++) {
                dp[i][j] = dp[i][j-1] + d;
            }
        }
        for (ll i=0; i<n; i++) {
            for (ll j=0; j<n; j++) {
                vals.push_back(dp[i][j]);
            }
        }
        sort(vals.begin(), vals.end());
        int flag = 0;
        for (ll i=0; i<n * n; i++) {
            if (vals[i]!=a[i]) {
                cout<<"NO"<<endl;
                flag = 1;
                break;
            }
        }
        if (flag==0) cout<<"YES"<<endl;
    }
    return 0;
}