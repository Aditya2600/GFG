class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
        int n = mat1.size();
        vector<int> v1, v2;
        
        // Flatten both matrices
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                v1.push_back(mat1[i][j]);
                v2.push_back(mat2[i][j]);
            }
        }

        // Sort not needed if input strictly follows conditions
        // But good for safety or messy inputs
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        int i = 0, j = v2.size() - 1;
        int count = 0;

        while (i < v1.size() && j >= 0) {
            int sum = v1[i] + v2[j];
            if (sum == x) {
                ++count;
                ++i;
                --j;
            } else if (sum < x) {
                ++i;
            } else {
                --j;
            }
        }

        return count;
    }
};