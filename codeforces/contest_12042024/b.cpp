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
            a.push_back(x);
        }
        if (n==1) {
            cout<<-1<<endl;
            continue;
        }
        ll be = a[0];
        bool beautiful = true;
        ll miniindex = n;
        ll max_index = -1;
        // ll last_index = -1;
        ll count = 2;
        ll min_op = n;
        for (ll i =1; i<n-1; i++) {
            if (a[i]==be) {
                count++;
                continue;
            }
            else {
                miniindex = min(miniindex, i);
                min_op = min(min_op, i - max_index - 1);
                max_index = max(max_index, i);
            }
        }
        if (count==n) {
            cout<<-1<<endl;
            continue;
        }
        min_op = min(min_op, min(miniindex, n - max_index - 1));
        cout<<min_op<<endl;
    }
    return 0;
}