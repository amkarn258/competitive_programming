#include <bits/stdc++.h>
#define ll long long int
#include <numeric>

using namespace std;

// ll getGCD(ll a, ll b) 
// { 
//     while (a > 0 && b > 0) { 
//         if (a > b) { 
//             a = a % b; 
//         } 
//         else { 
//             b = b % a; 
//         } 
//     } 
//     if (a == 0) { 
//         return b; 
//     } 
//     return a; 
// } 
  
// ll GcdOfArray(vector<ll>& arr) 
// { 
//     ll gcd = 0;
//     for (ll i = 1; i < arr.size(); i++) {
//         // if (arr[i]==1) continue;
//         gcd = getGCD(gcd, abs(arr[i] - arr[0])); 
//     } 
//     return max((ll)2, gcd);
// } 

vector<ll> get_all_multiples(ll n) {
    vector<ll> multiples;
    for (ll i=1; i * i<=n; i++) {
        if (n%i == 0) {
            multiples.push_back(i);
            if (i!=n/i) multiples.push_back(n/i);
        }
    }
    return multiples;
}

// bool check(vector<ll>& a, ll k, ll& maxi, ll m) {
//     if (k==a.size() || maxi==1) return true;
//     vector<ll> first_array;
//     for (ll i=0; i<k; i++) {
//         first_array.push_back(a[i] % m);
//     }
//     ll total_arrays = a.size() / k;
//     bool for_this_m = true;
//     for (ll i=1; i<total_arrays; i++) {
//         vector<ll> curr_array;
//         for (ll j = i * k; j< i * k + k; j++) {
//             if (a[j] % m != first_array[j - i*k]) {
//                 return false;
//             }
//         }
//     }
//     return true;
// }

int main() {
    ll t;
    cin>>t;
    ll ct = 1;
    while (t--) {
        ll n;
        cin>>n;
        vector<int> a;
        ll maxi = -1;
        for (ll i=0; i<n; i++) {
            int x;
            cin>>x;
            if (x > maxi) maxi = x;
            a.push_back(x);
        }
        vector<ll> multiples = get_all_multiples(n);
        sort(multiples.begin(), multiples.end());
        vector<bool> correct_or_not(n+1, false);
        ll count = 0;
        for (ll i=0; i<multiples.size(); i++) {
            if (correct_or_not[multiples[i]]) continue;
            ll k = multiples[i];
            int g = 0;
            for (int i = 0; i + k < n; i++) {
                g = __gcd(g, abs(a[i + k] - a[i]));
            }
            count += (g != 1);
        }
        cout<<count<<endl;
    }
    return 0;
}