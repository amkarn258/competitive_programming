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
        ll n, a, b;
        cin>>n>>a>>b;
        ll price = 0;
        if (b>=a*2) {
            price = a * n;
            cout<<price<<endl;
        }
        else {
            price = b * (n/2) + a * (n%2);
            cout<<price<<endl;
        }
    }
    return 0;
}