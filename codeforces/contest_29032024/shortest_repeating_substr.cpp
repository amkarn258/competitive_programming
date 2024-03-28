#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll solve(ll n, string s) {
    vector<ll> lengths;
    lengths.push_back(1);
    for (ll i=2; i<=n/2; i++) {
        if (n%i == 0) {
            lengths.push_back(i);
        }
    }
    for (auto x: lengths) {
        string a = s.substr(0, x);
        ll count = 0;
        bool possible = true;
        for (ll i=1; i<n/x; i++) {
            string curr = s.substr(i * x, x);
            for (ll j=0; j<x; j++) {
                if (curr[j] != a[j]) {
                    count++;
                }
                if (count > 1) {
                    possible = false;
                    break;
                }
            }
            if (!possible) break;
        }
        if (possible) return x;
        a = s.substr(n-x, x);
        count = 0;
        possible = true;
        for (ll i=0; i<n/x - 1; i++) {
            string curr = s.substr(i * x, x);
            for (ll j=0; j<x; j++) {
                if (curr[j] != a[j]) {
                    count++;
                }
                if (count > 1) {
                    possible = false;
                    break;
                }
            }
            if (!possible) break;
        }
        if (possible) return x;
    }
    return n;
}

int main() {
    ll t;
    cin>>t;
    while (t--) {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll ans = solve(n, s);
        cout<<ans<<endl;
    }
    return 0;
}