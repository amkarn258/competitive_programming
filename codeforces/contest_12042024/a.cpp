#include <bits/stdc++.h>
#define ll long long int
 
using namespace std;
 
int main() {
    ll t;
    cin>>t;
    while (t--) {
        ll n, m, k;
        cin>>n>>m>>k;
        if (m==1) {
            cout<<"NO"<<endl;
            continue;
        }
        if (n%m==0) {
            if (k>=(n-n/m)) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
        else {
            if (k>=n - (n/m + 1)) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
    return 0;
}