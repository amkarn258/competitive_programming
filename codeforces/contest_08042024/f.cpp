#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {
    ll t;
    cin>>t;
    while (t--) {
        vector<ll> p;
        for (ll i=0; i<4; i++) {
            ll x;
            cin>>x;
            p.push_back(x);
        }
        vector<vector<vector<vector<ll>>>> dp(p[0] + 1, vector<vector<vector<ll>>> (p[1] + 1, vector<vector<ll>> (p[2] + 1, vector<ll> (p[3] + 1, 0))));
        ll ans = 0;
        ll n = p[0] + p[1] + p[2] + p[3];
        vector<ll> answers(n + 1, -1);
        dp[0][0][0][0] = 0;
        for (ll i=0; i<=p[0]; i++) {
            for (ll j=0; j<=p[1]; j++) {
                for (ll k=0; k<=p[2]; k++) {
                    for (ll l=0; l<=p[3]; l++) {
                        if (i==0 && j==0 && k==0 && l==0) continue;
                        ll a = (i%2==0) ? 0: 1;
                        ll b = (j%2==0) ? 0: 2;
                        ll c = (k%2==0) ? 0: 3;
                        ll d = (l%2==0) ? 0: 4;
                        ll result = a^b;
                        result ^= c;
                        result ^= d;
                        ll maxi = 0;
                        if (i>0) maxi = max(maxi, dp[i-1][j][k][l]);
                        if (j>0) maxi = max(maxi, dp[i][j-1][k][l]);
                        if (k>0 && dp[i][j][k-1][l] > maxi) maxi = dp[i][j][k-1][l];
                        if (l>0) maxi = max(maxi, dp[i][j][k][l-1]);
                        dp[i][j][k][l] = maxi;
                        if (result==0) {
                            dp[i][j][k][l] += 1;
                        }
                    }
                }
            }
        }
        cout<<dp[p[0]][p[1]][p[2]][p[3]]<<endl;
    }
    return 0;
}