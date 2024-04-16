#include <bits/stdc++.h>
#define ll long long int

using namespace std;

// class PriorityDeque {
// private:
//     std::deque<T> dq;
//     std::priority_queue<T, std::vector<T>, std::greater<T>> pq;

// public:
//     void push(const T& element) {
//         dq.push_back(element);
//         pq.push(element);
//     }

//     void pop() {
//         pq.pop();
//         dq.pop_front();
//     }

//     const T& top() const {
//         return pq.top();
//     }

//     bool empty() const {
//         return dq.empty();
//     }

//     size_t size() const {
//         return dq.size();
//     }
// };


multiset<ll> s;

ll findMinCost(vector<ll>& row, ll d) {
    ll cost = 1;
    ll m = row.size();
    s.clear();
    s.insert(1);
    vector<ll> dp(m, -1);
    dp[0] = 1;
    for (ll i=1; i<m; i++) {
        if (i>d) s.erase(s.find(dp[i - d - 1]));
        dp[i] = *s.begin() + row[i] + 1;
        s.insert(dp[i]);
    }
    return dp[m-1];
}

int main() {
    ll t;
    cin>>t;
    while (t--) {
        ll n, m, k, d;
        cin>>n>>m>>k>>d;
        vector<vector<ll>> grid(n, vector<ll>(m, -1));
        for (ll i=0; i<n; i++) {
            for (ll j=0; j<m; j++) {
                ll x;
                cin>>x;
                grid[i][j] = x;
            }
        }
        d+=1;
        ll cost = 0;
        vector<ll> costs(n, -1);
        for (ll i=0; i<k; i++) {
            ll cost_i = findMinCost(grid[i], d);
            costs[i] = cost_i;
            cost += cost_i;
        }
        ll mincost = cost;
        for (ll i = k; i<n; i++) {
            cost -= costs[i-k];
            costs[i] = findMinCost(grid[i], d);
            cost += costs[i];
            mincost = min(mincost, cost);
        }
        cout<<mincost<<endl;
    }
    return 0;
}