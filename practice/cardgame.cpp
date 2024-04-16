#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {
    ll t;
    cin>>t;
    while (t--) {
        ll n; 
        cin>>n;
        char trp;
        cin>>trp;
        vector<vector<char>> cards(4);
        for (ll i=0; i<2*n; i++) {
            string x;
            cin>>x;
            if (x[1]=='C') cards[0].push_back(x[0]);
            else if (x[1]=='D') cards[1].push_back(x[0]);
            else if (x[1]=='H') cards[2].push_back(x[0]);
            else if (x[1]=='S') cards[3].push_back(x[0]);
        }
        map<char, ll> mp;
        mp['C'] = 0;
        mp['D'] = 1;
        mp['H'] = 2;
        mp['S'] = 3;
        map<ll, char> mp2;
        mp2[0] = 'C';
        mp2[1] = 'D';
        mp2[2] = 'H';
        mp2[3] = 'S';
        ll trump = mp[trp];
        vector<string> ans;
        ll num_trumps = cards[trump].size();
        sort(cards[trump].begin(), cards[trump].end());
        ll trump_idx = 0;
        bool flag = true;
        for (ll i=0; i<4; i++) {
            if (i==trump) continue;
            sort(cards[i].begin(), cards[i].end());
            if (cards[i].size()%2==0) {
                // string card_here = mp2[i];
                for (ll j=0; j<cards[i].size(); j++) {
                    string card_here = "";
                    card_here.push_back(cards[i][j]);
                    card_here.push_back(mp2[i]);
                    ans.push_back(card_here);
                }
            }
            else {
                for (ll j=0; j<cards[i].size(); j++) {
                    string card_here = "";
                    card_here.push_back(cards[i][j]);
                    card_here.push_back(mp2[i]);
                    ans.push_back(card_here);
                }
                // string card = cards[i][cards[i].size()-1] + mp2[i];
                if (trump_idx==num_trumps) {
                    flag = false;
                    break;
                }
                string trump_card = "";
                trump_card.push_back(cards[trump][trump_idx]);
                trump_card.push_back(mp2[trump]);
                ans.push_back(trump_card);
                trump_idx++;
            }
        }
        if (!flag) {
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }
        for (ll i=trump_idx; i<num_trumps; i++) {
            string trump_card = "";
            trump_card.push_back(cards[trump][i]);
            trump_card.push_back(mp2[trump]);
            ans.push_back(trump_card);
        }
        for (ll i=0; i<ans.size(); i++) {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}