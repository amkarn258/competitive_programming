#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {
    ll t;
    cin>>t;
    while (t--) {
        ll n, k;
        cin>>n>>k;
        vector<ll> elements(n);
        elements[0] = 1;
        ll idx = 1;
        for (ll i=1; i<k; i++) {
            if (idx%2==1) {
                elements[i] = elements[i-1] + (n-i)/k + (n-i-1)/k + 1;
            }
            else elements[i] = elements[i-1] + 1;
            idx++;
        }
        idx = 1;
        for (ll i=k; i<n; i++) {
            if (idx%2==1) {
                elements[i] = elements[i-k] + 1;
            }
            else elements[i] = elements[i-k] - 1;
            idx++;
        }
        for (ll i=0; i<n; i++) {
            cout<<elements[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}