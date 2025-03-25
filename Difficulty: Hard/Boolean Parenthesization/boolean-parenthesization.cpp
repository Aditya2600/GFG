//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int countWays(string &s) {
     int n = s.length();
        // dp[i][j][0]: number of ways to get false from i to j
        // dp[i][j][1]: number of ways to get true from i to j
        vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(n, {0,0}));
        
        // Base cases: single symbols
        for(int i = 0; i < n; i += 2) {
            if(s[i] == 'T') {
                dp[i][i] = {0, 1};  // 0 ways for false, 1 way for true
            } else {
                dp[i][i] = {1, 0};  // 1 way for false, 0 ways for true
            }
        }
        
        // Fill DP table for all lengths
        for(int len = 3; len <= n; len += 2) {
            for(int i = 0; i + len - 1 < n; i += 2) {
                int j = i + len - 1;
                // Try all possible operator positions between i and j
                for(int k = i + 1; k < j; k += 2) {
                    char op = s[k];
                    int leftFalse = dp[i][k-1].first;
                    int leftTrue = dp[i][k-1].second;
                    int rightFalse = dp[k+1][j].first;
                    int rightTrue = dp[k+1][j].second;
                    
                    // Calculate based on operator
                    if(op == '&') {
                        dp[i][j].first += leftFalse * rightFalse + 
                                        leftFalse * rightTrue + 
                                        leftTrue * rightFalse;
                        dp[i][j].second += leftTrue * rightTrue;
                    } 
                    else if(op == '|') {
                        dp[i][j].first += leftFalse * rightFalse;
                        dp[i][j].second += leftTrue * rightTrue + 
                                         leftTrue * rightFalse + 
                                         leftFalse * rightTrue;
                    } 
                    else if(op == '^') {
                        dp[i][j].first += leftFalse * rightFalse + 
                                        leftTrue * rightTrue;
                        dp[i][j].second += leftTrue * rightFalse + 
                                         leftFalse * rightTrue;
                    }
                }
            }
        }
        
        return dp[0][n-1].second;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        int ans = ob.countWays(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends