// User function Template for C++

class Solution {
  public:
    
    long long f(int i, int lastColor, int r[], int g[], int b[], int &N, vector<vector<long long>> &dp){
        if(i == N) return 0;
        if(dp[i][lastColor] != -1) return dp[i][lastColor];
        long long minCost = LLONG_MAX;
        if(lastColor != 0){
            minCost = min(minCost,1LL * r[i] + f(i+1, 0, r, g, b, N, dp));
        }
        if(lastColor != 1){
            minCost = min(minCost,1LL * g[i] + f(i+1, 1, r, g, b, N, dp));
        }
        if(lastColor != 2){
            minCost = min(minCost,1LL * b[i] + f(i+1, 2, r, g, b, N, dp));
        }
        return dp[i][lastColor] = minCost;
        
    }
        
    long long int distinctColoring(int N, int r[], int g[], int b[]) {
        // code here
        vector<vector<long long>> dp(N, vector<long long> (4, -1));
        return f(0, 3, r, g, b, N, dp);
    }
};