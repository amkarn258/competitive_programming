#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll N = 201;

vector<vector<vector<ll>>> dp(201, vector<vector<ll>> (201 + 1, vector<ll> (201 + 1, 0)));
void solve() {
    for (ll i=0; i<=N; i++) {
        for (ll j=0; j<=N; j++) {
            for (ll k=0; k<=N; k++) {
                if (i==0 && j==0 && k==0) continue;
                ll a = (i%2==0) ? 0: 1;
                ll b = (j%2==0) ? 0: 2;
                ll c = (k%2==0) ? 0: 3;
                ll result = a^b;
                result ^= c;
                ll maxi = 0;
                if (i>0) maxi = max(maxi, dp[i-1][j][k]);
                if (j>0) maxi = max(maxi, dp[i][j-1][k]);
                if (k>0 && dp[i][j][k-1] > maxi) maxi = dp[i][j][k-1];
                dp[i][j][k] = maxi;
                if (result==0) {
                    dp[i][j][k] += 1;
                }
            }
        }
    }
}

int main() {
    ll t;
    cin>>t;
    solve();
    while (t--) {
        vector<ll> p;
        for (ll i=0; i<4; i++) {
            ll x;
            cin>>x;
            p.push_back(x);
        }
        cout<<dp[p[0]][p[1]][p[2]] + p[3]/2<<endl;
    }
    return 0;
}