#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {
    ll t;
    cin>>t;
    while (t--) {
        ll n, m;
        cin>>n>>m;
        vector<ll> a;
        // ll product = 1%m;
        for (ll i=0; i<n; i++) {
            ll x;
            cin>>x;
            a.push_back(x);
            // product *= (x%m);
        }
        vector<char> s;
        for (ll i=0; i<n; i++) {
            char x;
            cin>>x;
            s.push_back(x);
        }
        vector<ll> b;
        ll l=0, r = n-1;
        for (ll i=0; i<n; i++) {
            if (s[i]=='L') {
                b.push_back(a[l]);
                l++;
            }
            else {
                b.push_back(a[r]);
                r--;
            }
        }
        vector<ll> ans(n, -1);
        ll pro = 1;
        for (ll i=n-1; i>=0; i--) {
            pro = (pro * b[i]%m)%m;
            ans[i] = pro;
        }
        for (ll i=0; i<n; i++) {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}