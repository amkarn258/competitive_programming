#include <bits/stdc++.h>
#define ll long long int

using namespace std;

// bool whowon(ll ones, ll zeroes, bool turn, ll size, string s) {
//     if (size==1) {
//         return !turn;
//         // else return false;
//     }
//     if (size==2) {
//         if (s[0]==s[1]) {
//             return turn;
//         }
//         else {
//             return !turn;
//         }
//     }
//     if (ones==zeroes) {
//         return !turn;
//         // if (turn==-1) return true;
//         // else return false;
//     }
//     bool ans = false;
//     ans |= whowon(ones-1, zeroes, !turn, size-1, s) | whowon(ones, zeroes-1, !turn, size-1, s);
//     return ans;
// }

int main() {
    ll t;
    cin>>t;
    while (t--) {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        if (n<=2) {
            if (n==1) cout<<"Bob"<<endl;
            else {
                if (s[0]==s[1]) cout<<"Alice"<<endl;
                else cout<<"Bob"<<endl;
            }
            continue;
        }
        ll ones = 0, zeroes = 0;
        for (ll i=0; i<n; i++) {
            if (s[i]=='1') ones++;
            else zeroes++;
        }
        if (ones==zeroes) cout<<"Bob"<<endl;
        else if ((abs(ones - zeroes)%2==0 && abs(ones - zeroes)>=2) || abs(ones - zeroes)==1) {
            cout<<"Alice"<<endl;
        }
        // else if (abs(ones - zeroes)==1) {
        //     cout<<"Alice"<<endl;
        // }
        else if (abs(ones - zeroes)%2==1 && abs(ones - zeroes)>2) {
            cout<<"Bob"<<endl;
        }
        else if (ones==0 || zeroes==0) {
            if (n%2==0) cout<<"Alice"<<endl;
            else cout<<"Bob"<<endl;
        }
    }
    return 0;
}