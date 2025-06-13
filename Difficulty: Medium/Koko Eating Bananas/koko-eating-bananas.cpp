class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int low = 1, high = *max_element(arr.begin(), arr.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long hours = 0;
            for (int bananas : arr) {
                hours += (bananas + mid - 1) / mid; // ceil(bananas / mid)
            }

            if (hours <= k) {
                ans = mid;       // try to minimize s
                high = mid - 1;
            } else {
                low = mid + 1;   // need to eat faster
            }
        }

        return ans;
    }
};