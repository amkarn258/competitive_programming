#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {
    ll t;
    cin>>t;
    while (t--) {
        ll n, m;
        cin>>n>>m;
        vector<ll> a, b;
        for (ll i=0; i<2; i++) {
            for (ll j=0; j<n; j++) {
                ll x;
                cin>>x;
                if (i==0) a.push_back(x);
                else b.push_back(x);
            }
        }
        
    }
    return 0;
}