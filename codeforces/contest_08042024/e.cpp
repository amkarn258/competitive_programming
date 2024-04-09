#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {
    ll t;
    cin>>t;
    while (t--) {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll count = 0;
        for (ll i=0; i<n; i++) {
            if (s[i]=='1') count++;
        }
        if (count==0 || count==n) {
            cout<<n<<endl;
            continue;
        }
        ll k = 1;
        string temp = s;
        ll temp_count = count;
        for (ll i=2; i<=n-1; i++) {
            s = temp;
            count = temp_count;
            ll first_zero = -1;
            for (ll j=0; j<n; j++) {
                if (s[j]=='0') {
                    first_zero = j;
                    break;
                }
            }
            ll next_zero = first_zero;
            while (true) {
                bool next_defined = false;
                ll temp_next_zero = next_zero;
                for (ll j = temp_next_zero; j<temp_next_zero + i; j++) {
                    if (s[j]=='1') {
                        s[j] = '0';
                        if (next_defined==false) {
                            next_zero = j;
                            next_defined = true;
                        }
                        count--;
                    }
                    else {
                        s[j] = '1';
                        count++;
                    }
                }
                if (count==n) {
                    k = i;
                    break;
                }
                
                if (!next_defined) {
                    for (ll j=next_zero + i; j<n; j++) {
                        if (s[j]=='0') {
                            next_zero = j;
                            break;             
                        }
                    }
                }
                if (next_zero > n - i) break;
            }
        }
        cout<<k<<endl;
    }
    return 0;
}