#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {
    ll t;
    cin>>t;
    while (t--) {
        ll n;
        cin>>n;
        vector<ll> a;
        for (ll i=0; i<n; i++) {
            ll x;
            cin>>x;
            ll add = 0;
            if (i!=0) add+=a[i-1];
            a.push_back(x + add);
        }
        ll q;
        cin>>q;
        for (ll i=0; i<q; i++) {
            ll l, u;
            cin>>l>>u;
            if (l>1) u += a[l-2];
            ll r = lower_bound(a.begin(), a.end(), u) - a.begin();
            if (r==n) {
                cout<<n<<" ";
                continue;
            }
            if (u>=a[r] || r==0) u-=a[r];
            else u -= a[r-1];
            ll last_dist = a[r];
            if (r>0) last_dist = a[r] - a[r-1];
            if (u==0 || u*2 + 1 > last_dist || r==0) r++;
            if (r<l) r = l;
            cout<<r<<" ";
        }
        cout<<endl;
    }
    return 0;
}