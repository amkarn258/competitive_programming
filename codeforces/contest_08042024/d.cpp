#include <bits/stdc++.h>
#define ll long long int
 
using namespace std;
 
int main() {
    ll t;
    cin>>t;
    while (t--) {
        ll n, m, k;
        cin>>n>>m>>k;
        vector<ll> a, b;
        for (ll i=0; i<n; i++) {
            ll x;
            cin>>x;
            a.push_back(x);
        }
        for (ll i=0; i<m; i++) {
            ll x;
            cin>>x;
            b.push_back(x);
        }
        map<ll, ll> btable;
        for (ll i=0; i<m; i++) {
            btable[b[i]]++;
        }
        ll count = 0;
        ll good = 0;
        for (ll i=0; i<m; i++) {
            if (btable.find(a[i])!=btable.end()) {
                btable[a[i]]--;
                if (btable[a[i]]>=0) count++;
            }
        }
        if (count>=k) good = 1;
        for (ll i=1; i<=n-m; i++) {
            ll gone_element = a[i-1];
            if (btable.find(gone_element)!=btable.end()) {
                btable[gone_element]++;
                if (btable[gone_element]>0) count--;
            }
            ll new_element = a[i + m - 1];
            if (btable.find(new_element)!=btable.end()) {
                btable[new_element]--;
                if (btable[new_element] >= 0) count++;
            }
            if (count >= k) good++;
        }
        cout<<good<<endl;
    }
    return 0;
}