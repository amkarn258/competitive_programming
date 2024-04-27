#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {
    ll t;
    cin>>t;
    while (t--) {
        ll h, w, xa, ya, xb, yb;
        cin>>h>>w>>xa>>ya>>xb>>yb;
        if (xa >= xb) {
            cout<<"DRAW"<<endl;
            continue;
        }
        ll height_diff = xb - xa;
        if (height_diff%2 == 1) {
            ll reach_bob = min(w, yb + height_diff / 2);
            ll reach_alice = min(w, ya + height_diff / 2 + 1);
            ll min_bob = max((ll)1, yb - height_diff/2);
            ll min_alice = max((ll)1, ya - height_diff/2 - 1);
            if (reach_alice>= reach_bob && min_alice<=min_bob) {
                cout<<"ALICE"<<endl;
            }
            else cout<<"DRAW"<<endl;
        }
        else {
            ll reach_alice = min(w, ya + height_diff / 2);
            ll reach_bob = min(w, yb + height_diff / 2);
            ll min_alice = max((ll)1, ya - height_diff / 2);
            ll min_bob = max((ll)1, yb - height_diff / 2);
            if (reach_bob>= reach_alice && min_bob<=min_alice) {
                cout<<"BOB"<<endl;
            }
            else cout<<"DRAW"<<endl;
        }
    }
    return 0;
}