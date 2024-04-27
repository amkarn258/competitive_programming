#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll t;
    cin>>t;
    while (t--) {
        ll n;
        cin>>n;
        // vector<vector<char>> v(n*2, vector<char>(n*2, '.'));
        for (ll i=0; i<n*2; i++) {
            for (ll j=0; j<n*2; j++) {
                if ((i/2)%2==0) {
                    if ((j/2)%2==0) {
                        cout<<"#";
                    }
                    else cout<<".";
                }
                else {
                    if ((j/2)%2==0) {
                        cout<<".";
                    }
                    else cout<<"#";
                }
            }
            cout<<endl;
        }
    }
    return 0;
}