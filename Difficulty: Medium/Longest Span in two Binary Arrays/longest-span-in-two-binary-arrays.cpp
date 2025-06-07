class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        // Code here.
        int n = a1.size();
        unordered_map<int, int> firstOccurrence;
        int maxLen = 0;
        int prefixSum = 0;

        for (int i = 0; i < n; ++i) {
            int diff = a1[i] - a2[i];
            prefixSum += diff;

            if (prefixSum == 0) {
                maxLen = i + 1;  // from 0 to i
            }

            if (firstOccurrence.find(prefixSum) != firstOccurrence.end()) {
                maxLen = max(maxLen, i - firstOccurrence[prefixSum]);
            } else {
                firstOccurrence[prefixSum] = i;
            }
        }

        return maxLen;
    }
};