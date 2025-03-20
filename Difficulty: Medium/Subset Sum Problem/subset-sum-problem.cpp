//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    // bool f(int ind, vector<int>& arr, int sum, vector<vector<int>> &dp){
    //     if(sum == 0) return true;
    //     if(ind == 0) return (arr[0] == sum);
    //     if(dp[ind][sum] != -1) return dp[ind][sum];
    //     bool notTake = f(ind-1, arr, sum, dp);
    //     bool take = false;
    //     take = f(ind - 1, arr, sum - arr[ind], dp);
    //     return dp[ind][sum] = take | notTake;
    // }
    
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
    //     vector<vector<bool>> dp(n+1, vector<bool>(sum+1, 0));
    //     for(int i=0; i<n; i++) dp[i][0] = true;
    //     dp[0][arr[0]] = true;
    //     for(int ind = 1; ind<n; ind++){
    //         for(int k = 1; k<=sum; k++){
    //             bool notTake = dp[ind-1][k];
    //             bool take = false;
    //             if(arr[ind] <= k)take = dp[ind-1][k - arr[ind]];
    //             dp[ind][k] = notTake | take;
    //         }
    //     }
    //     return dp[n-1][sum];
    // }
    //     vector<vector<int>> dp(n+1, vector<int> (sum+1, -1));
    //     return f(n-1, arr, sum, dp);
    // }
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
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends