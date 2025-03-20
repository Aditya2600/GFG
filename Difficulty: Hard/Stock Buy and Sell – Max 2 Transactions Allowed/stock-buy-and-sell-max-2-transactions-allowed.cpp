//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
int dp[100005][10][2];
    int f(vector<int> &prices, int i, int k, bool on){
        int n = prices.size();
        int res = INT_MIN;
        if(dp[i][k][on] != -1) return dp[i][k][on];
        if(i == n) return 0;
        res = f(prices, i+1, k, on);
        if(on){
            res = max(res, prices[i] + f(prices, i+1, k-1, false));
        } 
        else{
            if(k>0){
                res = max(res, f(prices, i+1, k, true) - prices[i]);
            }
        }
        return dp[i][k][on] = res;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        int n = prices.size();
        return f(prices, 0, 2, false);
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends