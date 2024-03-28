#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector<bool> is_product(1e5 + 1, false);

void seiveModified() {
    is_product[1] = true;
    is_product[0] = true;
    int Num = 1e5;
    for (int i=2; i<=Num; i++) {
        string a = to_string(i);
        bool is_binary = true;
        for (int j=0; j<a.length(); j++) {
            if (a[j]!='0' && a[j]!='1') {
                is_binary = false;
                break;
            }
        }
        if (is_binary) {
            is_product[i] = true;
        }
    }
    for (int i=2; i*i<=Num; i++) {
        if (is_product[i]) {
            for (int j=i*i; j<=Num; j+=i) {
                if (!is_product[j/i]) continue;
                is_product[j] = true;
            }
        }
    }
}

int main() {
    ll t;
    cin>>t;
    seiveModified();
    while (t--) {
        ll n;
        cin>>n;
        if (is_product[n]) {
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}