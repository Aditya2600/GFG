class Solution {
  public:
    int countSubstr(string& s, int k) {
        // code here.
        return atMostK(s, k) - atMostK(s, k - 1);
    }
    private:
    int atMostK(const string& s, int k) {
        if (k == 0) return 0;
        int n = s.length();
        unordered_map<char, int> freq;
        int left = 0, res = 0;

        for (int right = 0; right < n; ++right) {
            freq[s[right]]++;
            while (freq.size() > k) {
                freq[s[left]]--;
                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }
                left++;
            }
            res += right - left + 1;
        }

        return res;
    }
};