#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {
    ll t;
    cin>>t;
    while (t--) {
        ll n, k, m;
        cin>>n>>k>>m;
        string s;
        cin>>s;
        set<char> st;
        map<char, bool> found;
        ll idx = 0;
        for (char x = 'a'; x<='z' && idx<k; x++) {
            found[x] = false;
            idx++;
        }
        ll num_found = 0;
        string first = "";
        for (ll i=0; i<m; i++) {
            if (found.find(s[i])!=found.end()) {
                st.insert(s[i]);
                found[s[i]] = true;
                num_found++;
            }
            if (st.size()==k) {
                first += s[i];
                st.clear();
            }
        }
        // cout<<"first is "<<first<<endl;
        if (first.length()>=n) {
            cout<<"YES"<<endl;
        }
        else {
            char to_add;
            for (auto x: found) {
                if (st.find(x.first)==st.end()) {
                    to_add = x.first;
                    break;
                }
            }
            ll len = first.length();
            for (ll i=len; i<n; i++) {
                first += to_add;
            }
            cout<<"NO"<<endl;
            cout<<first<<endl;
        }
    }
    return 0;
}