#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll t;
    cin>>t;
    while (t--) {
        string s;
        cin>>s;
        bool am = true;
        int hour = stoi(s.substr(0, 2));
        if (hour>=12) {
            am = false;
        }
        hour = hour % 12;
        if (hour==0) hour = 12;
        string ans = "";
        if (hour<10) ans += '0';
        ans += to_string(hour) + ':' + s.substr(3,2) + ' ';
        if (am) {
            ans += "AM";
        }
        else ans += "PM";
        cout<<ans<<endl;
    }
    return 0;
}