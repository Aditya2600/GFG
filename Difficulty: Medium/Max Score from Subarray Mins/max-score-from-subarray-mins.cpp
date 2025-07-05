class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int n = arr.size();
        int maxSum = 0;
        
        for(int i = 0; i < n - 1; ++i) {
            // Subarray of size 2
            int a = arr[i], b = arr[i+1];
            int sum2 = min(a, b) + max(a, b);
            maxSum = max(maxSum, sum2);
            
            // Subarray of size 3
            if(i + 2 < n) {
                int x = arr[i], y = arr[i+1], z = arr[i+2];
                // Find two smallest
                vector<int> temp = {x, y, z};
                sort(temp.begin(), temp.end());
                int sum3 = temp[0] + temp[1];
                maxSum = max(maxSum, sum3);
            }
        }
        
        return maxSum;
    }
};