class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        // ✅ Min-heap to store top k largest sums
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int sum = a[i] + b[j];

                // ✅ If heap not full, push sum
                if (pq.size() < k) {
                    pq.push(sum);
                }
                // ✅ If current sum > smallest in heap, replace
                else if (sum > pq.top()) {
                    pq.pop();
                    pq.push(sum);
                } 
                // ✅ Optimization: break since smaller sums ahead
                else break;
            }
        }

        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        reverse(ans.begin(), ans.end()); // largest to smallest
        return ans;
    }
};