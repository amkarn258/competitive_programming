#include <bits/stdc++.h>
#define ll long long int

using namespace std;

string addLargeNumbers(const string& num1, const string& num2) {
    string result;
    
    int carry = 0;
    int max_length = max(num1.length(), num2.length());
    
    // Pad the numbers with zeros to make them of equal length
    string padded_num1(max_length - num1.length(), '0');
    string padded_num2(max_length - num2.length(), '0');
    padded_num1.append(num1);
    padded_num2.append(num2);

    // Iterate through the digits from right to left
    for (int i = max_length - 1; i >= 0; --i) {
        int digit_sum = (padded_num1[i] - '0') + (padded_num2[i] - '0') + carry;
        result.insert(result.begin(), '0' + (digit_sum % 10));
        carry = digit_sum / 10;
    }

    if (carry) {
        result.insert(result.begin(), '0' + carry);
    }

    return result;
}

string countdown(string a, string count, ll i, ll start) {
    // ll ct = 0;
    if (start==i && a[i]=='0') return count;
    while (start < i) {
        if (a[i]=='0') {
            a[i] = '9';
            ll ct = 1;
            // count = addLargeNumbers(count, "1");
            ll j = i-1;
            while (a[j]=='0' && j>=0) {
                a[j] = '9';
                j--;
                ct++;
            }
            count = addLargeNumbers(count, to_string(ct));
            a[j] = a[j] - '1';
            if (j==0 && a[j]=='0') start++;
        }
        else {
            count = addLargeNumbers(count, a[i]);
            a[i] = '0';
            if (start==i) break;
        }
    }
    return count;
}

int main() {
    ll t;
    cin>>t;
    while (t--) {
        ll n;
        cin>>n;
        string a;
        cin>>a;
        string count = countdown(a, "0", n-1, 0);
        cout<<count<<endl;
    }
    return 0;
}