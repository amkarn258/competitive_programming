#include <bits/stdc++.h>
#define ll long long int
 
using namespace std;
 
int main() {
    ll t;
    cin>>t;
    while (t--) {
        string x, y;
        cin>>x>>y;
        ll n = x.length();
        ll i = 0;
        while (x[i]==y[i] && i<n) i++;
        if (i==n) {
            cout<<x<<"\n"<<y<<endl;
            continue;
        }
        if (x[i]>y[i]) swap(x[i], y[i]);
        for (ll j = i + 1; j<n; j++) {
            if (x[j]<y[j]) swap(x[j], y[j]);
        }
        cout<<x<<"\n"<<y<<endl;
    }
    return 0;
}
