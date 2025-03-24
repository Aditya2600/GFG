//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> dp;

    int matrixChainMultiplication(vector<int>& arr, int i, int j) {
        if (i == j) return 0;  // Single matrix, no multiplication needed
        if (dp[i][j] != -1) return dp[i][j];  // Return cached result

        int minCost = INT_MAX;

        // Try every split point
        for (int k = i; k < j; k++) {
            int cost = matrixChainMultiplication(arr, i, k) + 
                       matrixChainMultiplication(arr, k + 1, j) + 
                       arr[i - 1] * arr[k] * arr[j];

            minCost = min(minCost, cost);
        }

        return dp[i][j] = minCost;
    }

    int matrixMultiplication(vector<int>& arr) {
        int N = arr.size();
        dp.assign(N, vector<int>(N, -1));  // Initialize DP table with -1
        return matrixChainMultiplication(arr, 1, N - 1);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl << "~\n";
    }

    return 0;
}

// } Driver Code Ends