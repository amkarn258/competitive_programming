#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while (t--) {
        int n;
        int l;
        cin>>n>>l;
        vector<int> dp(n);
        dp[0] = 1;
        int i = 1;
        int curr_sum = dp[0] * 2 + 1;
        while (curr_sum < l && i<n) {
            dp[i] = dp[i-1] + 1;
            curr_sum = dp[i] * 2 + 1;
            i++;
        }
        for (int x = i; x<n; x++) {
            dp[x] = dp[x-1] + l;
        }
        for (int i=0; i<n; i++) {
            cout<<dp[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}