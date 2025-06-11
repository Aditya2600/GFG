class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        // code here
        stack<pair<int, int>> st;
        int n = color.size();
        
        for (int i = 0; i < n; ++i) {
            pair<int, int> current = {color[i], radius[i]};
            
            if (!st.empty() && st.top() == current) {
                st.pop(); // remove the pair
            } else {
                st.push(current);
            }
        }
        
        return st.size();
    }
};