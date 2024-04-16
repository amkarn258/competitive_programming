#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {
    ll t;
    cin>>t;
    while (t--) {
        ll n, m;
        cin>>n>>m;
        vector<string> a;
        // ll product = 1%m;
        ll digits = 0;
        // vector<ll> zeroes;
        priority_queue<pair<int, int>> pq;
        for (ll i=0; i<n; i++) {
            string x;
            cin>>x;
            digits += x.length();
            ll lead_zeroes = 0;
            ll j = x.length() - 1;
            while (x[j]=='0') {
                lead_zeroes++;
                j--;
            }
            if (lead_zeroes>0) pq.push({lead_zeroes, i});
            a.push_back(x);
        }
        if (digits <= m) {
            cout<<"Anna"<<endl;
            continue;
        }
        ll i = 0;
        bool flag = true;
        // cout<<digits<<endl;
        while (!pq.empty()) {
            ll zeroes_here = pq.top().first;
            // cout<<"zeroes_here = "<<zeroes_here<<endl;
            ll idx = pq.top().second;
            if (i%2==0) {
                digits -= zeroes_here;
            }
            pq.pop();
            if (digits<=m) {
                flag = false;
                break;
            }
            i++;
        }
        // cout<<digits<<endl;
        if (!flag || digits<=m) cout<<"Anna"<<endl;
        else cout<<"Sasha"<<endl; 
    }
    return 0;
}