class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        if (n <= 1) return 0;

        // dp[i][j] = LPS length in s[i..j]
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // substrings of length 1
        for (int i = 0; i < n; ++i) dp[i][i] = 1;

        // build for increasing lengths
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = 2 + (i+1 <= j-1 ? dp[i+1][j-1] : 0);
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }

        int lps = dp[0][n-1];
        return n - lps;
    }
};