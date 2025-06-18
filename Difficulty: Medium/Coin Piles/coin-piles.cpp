class Solution {
  public:
    int minimumCoins(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        vector<long long> prefix(n);
        prefix[0] = arr[0];
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + arr[i];
        }

        long long totalSum = prefix[n-1];
        long long ans = LLONG_MAX;

        for(int i = 0; i < n; i++) {
            // arr[i] is considered as the minimum
            int maxAllowed = arr[i] + k;
            
            // Find the last position where arr[pos] <= maxAllowed
            int pos = upper_bound(arr.begin(), arr.end(), maxAllowed) - arr.begin();

            // Remove all piles before i completely (i piles)
            long long removeLeft = (i > 0) ? prefix[i-1] : 0;

            // Remove excess coins from arr[pos] to arr[n-1]
            long long keepRightPiles = (n - pos) * 1LL * maxAllowed;
            long long sumRight = (pos < n) ? (prefix[n-1] - prefix[pos - 1]) : 0;
            long long removeRight = (pos < n) ? (sumRight - keepRightPiles) : 0;

            ans = min(ans, removeLeft + removeRight);
        }

        return (int)ans;
    }
};