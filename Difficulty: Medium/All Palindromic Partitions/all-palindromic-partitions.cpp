class Solution {
  public:
    
    void f(vector<vector<string>>& res, vector<string>& path, string &s, int ind){
        if(ind == s.size()){
            res.push_back(path);
            return;
        }
        for(int i=ind; i<s.size(); i++){
            if(isPalindrome(s, ind, i)){
                path.push_back(s.substr(ind, i-ind+1));
                f(res, path, s, i+1);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(string &s, int ind, int end){
        while(ind <= end){
            if(s[ind++] != s[end--]){
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> palinParts(string &s) {
        // code here
        vector<vector<string>> res;
        vector<string> path;
        f(res, path, s, 0);
        return res;
    }
};