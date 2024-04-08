#include <bits/stdc++.h>
#define ll long long int
 
using namespace std;
 
int main() {
    ll t;
    cin>>t;
    while (t--) {
        ll n, k;
        cin>>n>>k;
        vector<ll> a;
        for (ll i=0; i<n; i++) {
            ll x;
            cin>>x;
            a.push_back(x);
        }
        ll left = 0, right = n-1, sunk = 0;
        ll i = 0;
        ll start = -1;
        while (k>0) {
            ll mini_operations;
            if (sunk>=n) break;
            if (left==right) {
                ll tem = a[left];
                a[left] -= min(a[left], k);
                k -= min(tem, k);
                if (a[left]<=0) sunk++;
                break;
            }
            if (start==-1) {
                if (a[left] <= a[right]) {
                    mini_operations = a[left] * 2 - 1;
                }
                else mini_operations = a[right] * 2;
                if (k<mini_operations) {
                    break;
                }
                else {
                    if (a[left] <= a[right]) {
                        k -= mini_operations;
                        left++;
                        sunk++;
                        a[right] -= mini_operations / 2;
                    }
                    else {
                        k -= mini_operations;
                        right--;
                        sunk++;
                        a[left] -= (mini_operations / 2);
                    }
                }
                if (mini_operations % 2 == 1) {
                    start *= -1;
                }
            }
            else if (start==1) {
                if (a[right] <= a[left]) {
                    mini_operations = a[right] * 2 - 1;
                }
                else mini_operations = a[left] * 2;
                if (k<mini_operations) {
                    break;
                }
                else {
                    if (a[right] <= a[left]) {
                        k -= mini_operations;
                        right--;
                        sunk++;
                        a[left] -= mini_operations / 2;
                    }
                    else {
                        k -= mini_operations;
                        left++;
                        sunk++;
                        a[right] -= (mini_operations / 2);
                    }
                }
                if (mini_operations % 2 == 1) {
                    start *= -1;
                }
            }
        }
        cout<<sunk<<endl;
    }
    return 0;
}