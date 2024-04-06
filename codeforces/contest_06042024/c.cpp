#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {
    ll t;
    cin>>t;
    while (t--) {
        ll n, m, k;
        cin>>n>>m>>k;
        vector<ll> a;
        for (ll i=0; i<n; i++) {
            ll x;
            cin>>x;
            a.push_back(x);
        }
        ll minelements = k / m;
        if (k%m!=0) minelements++;
        priority_queue<pair<ll, ll>> pq;
        for (int i=0; i<n; i++) {
            pq.push({a[i], i});
            if (pq.size() > minelements) {
                pq.pop();
            }
        }
        int minsum = 0;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pqindices;
        ll maxelement = pq.top().first;
        while (!pq.empty()) {
            pqindices.push({pq.top().second, pq.top().first});
            pq.pop();
        }
        ll iterations = 0;
        ll add_till_now = 0;
        ll ans = 0;
        ll tickets = 0;
        while (!pqindices.empty() && k>0) {
            ll curr = pqindices.top().second;
            ll i = pqindices.top().first;
            pqindices.pop();
            if (curr == maxelement && k%m!=0) {
                ans += (curr + add_till_now) * (k%m);
                add_till_now += (k%m);
                tickets += (k%m);
                k -= (k%m);
            }
            else {
                ans += (curr + add_till_now) * m;
                add_till_now += m;
                tickets += m;
                k -= m;
            }
        }
        cout<<ans<<endl;
    }   
    return 0;
}