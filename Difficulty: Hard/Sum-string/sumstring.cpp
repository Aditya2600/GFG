class Solution {
  public:
 string addStrings(string a, string b) {
        string result = "";
        int i = a.length() - 1, j = b.length() - 1, carry = 0;
        
        while (i >= 0 || j >= 0 || carry) {
            int digitA = (i >= 0 ? a[i--] - '0' : 0);
            int digitB = (j >= 0 ? b[j--] - '0' : 0);
            int sum = digitA + digitB + carry;
            carry = sum / 10;
            result += (sum % 10 + '0');
        }
        
        reverse(result.begin(), result.end());
        return result;
    }

    bool checkSumString(string &s, int start, int len1, int len2) {
        string s1 = s.substr(start, len1);
        string s2 = s.substr(start + len1, len2);

        if ((s1.length() > 1 && s1[0] == '0') || (s2.length() > 1 && s2[0] == '0'))
            return false;

        string sum = addStrings(s1, s2);
        int sumLen = sum.length();

        if (start + len1 + len2 + sumLen > s.length()) return false;

        string s3 = s.substr(start + len1 + len2, sumLen);
        if (s3 != sum) return false;

        if (start + len1 + len2 + sumLen == s.length()) return true;

        return checkSumString(s, start + len1, len2, sumLen);
    }

    bool isSumString(string &s) {
        // code here
         int n = s.length();

        for (int len1 = 1; len1 <= n / 2; len1++) {
            for (int len2 = 1; len2 <= (n - len1) / 2; len2++) {
                if (checkSumString(s, 0, len1, len2)) return true;
            }
        }
        return false;
    }
};