#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll find_min(ll a, ll k) {
    ll left = 1, right = a/2 + 1;
    while (left<right) {
        ll mid = (left + right) / 2;
        if (mid * k <= a) {
            left = mid + 1;
        }
        else right = mid;
    }
    return left;
}

int main() {
    ll t;
    cin>>t;
    while (t--) {
        ll k, x, a;
        cin>>k>>x>>a;
        if (a<=x) {
            cout<<"NO"<<endl;
            continue;
        }
        ll after_first_x_rounds = a - x;
        after_first_x_rounds *= k;
        if (after_first_x_rounds<=a) {
            cout<<"NO"<<endl;
            continue;
        }
        if (a - x + 1 + k-1 > a) {
            cout<<"YES"<<endl;
            continue;
        }
        ll min_possible = -1;
        ll l = find_min(a, k);
        min_possible = l;
        ll count = x-1;
        bool flag = true;
        ll last_l = l;
        while (count) {
            ll r = a - 1;
            while (l<r) {
                if (a - l < count) {
                    flag = false;
                    break;
                }
                ll mid = (l + r)/2;
                ll diff = mid - last_l;
                if (diff * (k-1) + mid > a) {
                    r = mid;
                }
                else {
                    l = mid + 1;
                }
            }
            l = r + 1;
            if (a - r < count || !flag || (r - last_l) * (k-1) + r <= a) {
                flag = false;
                break;
            }
            last_l = r;
            count--;
        }
        if (!flag) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}