class Solution {
  public:
    long long ncr(int n, int r) {
        long long ans = 1;
        for (int i = 1; i <= min(r, n - r); i++) {
            ans = (ans * (n - i + 1)) / i;
        }
        return ans;
    }
    int numberOfPaths(int m, int n) {
        // Code Here
        return ncr(m + n - 2, min(m - 1, n - 1)); 
    }
};
