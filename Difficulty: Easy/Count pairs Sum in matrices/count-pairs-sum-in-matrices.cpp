class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
        unordered_set<int> elements;  // to store elements of mat2
        int n = mat1.size();
        
        // Insert all elements of mat2 into the set
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                elements.insert(mat2[i][j]);
        
        int count = 0;

        // Check for complement of each element in mat1
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                int a = mat1[i][j];
                if (elements.find(x - a) != elements.end())
                    count++;
            }

        return count;
    }
};