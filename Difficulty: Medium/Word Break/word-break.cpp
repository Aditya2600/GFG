//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool wordBreak(string &s, vector<string> &dictionary) {
        // code here
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;  // Empty string is segmentable
        
        // Use unordered_set for O(1) lookup
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        
        // For each ending position
        for(int i = 1; i <= n; i++) {
            // Try matching words from dictionary ending at i
            for(const string& word : dictionary) {
                int len = word.length();
                if(i >= len && dp[i - len]) {
                    // Check if substring matches word
                    if(s.substr(i - len, len) == word) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        
        return dp[n];
    }
};


//{ Driver Code Starts.

vector<string> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    vector<string> res;
    while (ss >> str) {
        res.push_back(str);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        cin >> s;
        cin.ignore();
        vector<string> dictionary = inputLine();

        Solution ob;
        if (ob.wordBreak(s, dictionary)) {
            cout << "true\n";
        } else
            cout << "false\n";
        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends