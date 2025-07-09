class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;
        vector<int> ple(n), nle(n);
        stack<int> st;

        // Find Previous Less Element (PLE)
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            ple[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Clear stack for next calculation
        while (!st.empty()) st.pop();

        // Find Next Less Element (NLE)
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            nle[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Calculate result
        long long res = 0;
        for (int i = 0; i < n; ++i) {
            long long left = i - ple[i];
            long long right = nle[i] - i;
            res = (res + arr[i] * left * right) % MOD;
        }

        return (int)res;
    }
};