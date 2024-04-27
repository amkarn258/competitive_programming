#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool isSuperincreasing(int N, int K, int X) {
    if (K == 1) {
        return X == 1;
    }
    int sum_so_far = 1;
    for (int i = 2; i <= N; ++i) {
        if (i == K) {
            sum_so_far += X;
        } else if (i < K) {
            sum_so_far += 1;
        } else {
            if (sum_so_far >= X) {
                return false;
            }
            sum_so_far *= 2;
        }
    }
    return true;
}

int main() {
	// your code goes here
    ll t;
    cin>>t;
    while (t--) {
        ll N;
        ll K;
        ll X;
        cin>>N>>K>>X;
        vector<int> dp(K);
        dp[0] = 1;
        ll sum = dp[0];
        int flag = 0;
        for (int i=1; i<K; i++) {
            dp[i] = sum + 1;
            sum += dp[i];
            if (dp[i] > X) {
                cout<<"No"<<endl;
                flag = -1;
                break;
            }
        }
        if (flag==-1) continue;
        else {
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}