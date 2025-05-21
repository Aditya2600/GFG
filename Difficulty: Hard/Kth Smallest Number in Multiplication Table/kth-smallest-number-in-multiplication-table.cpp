class Solution {
  public:
    int kthSmallest(int m, int n, int k) {
      auto count = [&](int x) {
        int total = 0;
        for (int i = 1; i <= m; i++) {
            total += min(x / i, n);
        }
        return total;
    };
    
    int low = 1, high = m * n;
    while (low < high) {
        int mid = (low + high) / 2;
        if (count(mid) < k)
            low = mid + 1;
        else
            high = mid;
    }
    return low;  // code here
        
    }
};
