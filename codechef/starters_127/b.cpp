#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
	// your code goes here
    ll t;
    cin>>t;
    while (t--) {
        int A;
        int B;
        cin>>A;
        cin>>B;
        int shots = 0;
        if (A-B >=10) {
            cout<<shots<<endl;
            continue;
        }
        while (A - B < 10) {
            A += 3;
            shots++;
        }
        cout<<shots<<endl;
    }
}