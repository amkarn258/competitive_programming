#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll t;
    cin>>t;
    while (t--) {
        ll a, b, c;
        cin>>a>>b>>c;
        if (a < b && b < c) {
            cout<<"STAIR"<<endl;
            continue;
        }
        else if (a<b && b > c) {
            cout<<"PEAK"<<endl;
            continue;
        }
        else {
            cout<<"NONE"<<endl;
        }
    }
    return 0;
}