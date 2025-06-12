class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
       int n = arr.size();
        vector<int> ans;
        deque<int> dq;  // store indices of negative numbers

        for (int i = 0; i < n; i++) {
            // Push index if current element is negative
            if (arr[i] < 0)
                dq.push_back(i);

            // Remove elements from front if they are out of this window
            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Record result once window is formed
            if (i >= k - 1) {
                if (!dq.empty())
                    ans.push_back(arr[dq.front()]);
                else
                    ans.push_back(0);
            }
        }

        return ans;
    }
};