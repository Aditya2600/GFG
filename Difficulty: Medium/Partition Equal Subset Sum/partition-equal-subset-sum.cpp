//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<bool> prev(sum+1, 0), cur(sum+1, 0);
        prev[0] = cur[0] = true;
        prev[arr[0]] = true;
        for(int ind = 1; ind<n; ind++){
            for(int k=1; k<=sum; k++){
                bool notTake = prev[k];
                bool take = false;
                if(arr[ind] <= k) take = prev[k - arr[ind]];
                cur[k] = take | notTake;
            }
            prev = cur;
        }
        return prev[sum];
    }
    
    bool equalPartition(vector<int>& arr) {
        // code here
        int n = arr.size();
        int totSum = 0;
        for(int i=0; i<n; i++) totSum += arr[i];
        if(totSum % 2) return false;
        return isSubsetSum(arr, totSum/2);
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
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends