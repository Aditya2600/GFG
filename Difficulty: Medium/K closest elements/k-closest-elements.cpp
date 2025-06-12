class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        // Code here
        int n = arr.size();
        vector<int> res;

        // Step 1: Binary search to find first number >= x
        int right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int left = right - 1;

        // Step 2: Skip x if present
        if (right < n && arr[right] == x) {
            right++;
        }

        // Step 3: Pick k closest elements
        while (k > 0 && (left >= 0 || right < n)) {
            if (left < 0) {
                res.push_back(arr[right++]);
            } else if (right >= n) {
                res.push_back(arr[left--]);
            } else {
                int diffLeft = abs(arr[left] - x);
                int diffRight = abs(arr[right] - x);

                if (diffLeft < diffRight) {
                    res.push_back(arr[left--]);
                } else if (diffRight < diffLeft) {
                    res.push_back(arr[right++]);
                } else {
                    // Same difference → prefer larger element
                    if (arr[left] > arr[right]) {
                        res.push_back(arr[left--]);
                    } else {
                        res.push_back(arr[right++]);
                    }
                }
            }
            k--;
        }

        return res;
    }
};