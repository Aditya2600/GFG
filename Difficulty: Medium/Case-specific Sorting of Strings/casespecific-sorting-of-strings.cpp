class Solution {
  public:
    string caseSort(string& s) {
        // code here
        vector<char> upper,lower;
        for(char ch : s){
            if(islower(ch)){
                lower.push_back(ch);
            }
            else upper.push_back(ch);
        }
        sort(upper.begin(), upper.end());
        sort(lower.begin(), lower.end());
        string ans = "";
        int llindex = 0, upindex = 0;
        for(char ch : s){
            if(islower(ch)){
                ans += lower[llindex++];
            }
            else{
                ans += upper[upindex++];
            }
        }
        return ans;
    }
};