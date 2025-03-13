//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool canPair(vector<int> &arr, int k) {
        unordered_map<int, int> freq;

        // Count remainder frequencies
        for (int num : arr) {
            int rem = num % k;
            freq[rem]++;
        }

        // Check pairing conditions
        for (auto it : freq) {
            int rem = it.first;
            int count = it.second;

            // Special case: remainder 0 must have even count
            if (rem == 0 && count % 2 != 0) return false;

            // Normal case: freq[rem] must match freq[k-rem]
            if (rem != 0 && freq[rem] != freq[k - rem]) return false;
        }
        return true;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution obj;
        bool ans = obj.canPair(arr, k);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends