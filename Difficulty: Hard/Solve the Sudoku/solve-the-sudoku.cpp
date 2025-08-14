class Solution 
{
public:
    bool isSafe(int i, int j, int num, 
                const vector<int> &row, const vector<int> &col, const vector<int> &box) {
        return !(row[i] & (1 << num)) &&
               !(col[j] & (1 << num)) &&
               !(box[(i / 3) * 3 + j / 3] & (1 << num));
    }
    
    bool solveRec(vector<vector<int>> &mat, int i, int j, 
                  vector<int> &row, vector<int> &col, vector<int> &box) {
        int n = 9;

        // If we filled all rows
        if (i == n - 1 && j == n) return true;

        // Move to next row
        if (j == n) return solveRec(mat, i + 1, 0, row, col, box);

        // Skip filled cells
        if (mat[i][j] != 0) return solveRec(mat, i, j + 1, row, col, box);

        // Try numbers 1-9
        for (int num = 1; num <= n; num++) {
            if (isSafe(i, j, num, row, col, box)) {
                mat[i][j] = num;
                row[i] |= (1 << num);
                col[j] |= (1 << num);
                box[(i / 3) * 3 + j / 3] |= (1 << num);

                if (solveRec(mat, i, j + 1, row, col, box))
                    return true;

                // Backtrack
                mat[i][j] = 0;
                row[i] &= ~(1 << num);
                col[j] &= ~(1 << num);
                box[(i / 3) * 3 + j / 3] &= ~(1 << num);
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<int>> &mat) {
        int n = 9;
        vector<int> row(n, 0), col(n, 0), box(n, 0);

        // Initialize bitmasks
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != 0) {
                    row[i] |= (1 << mat[i][j]);
                    col[j] |= (1 << mat[i][j]);
                    box[(i / 3) * 3 + j / 3] |= (1 << mat[i][j]);
                }
            }
        }

        solveRec(mat, 0, 0, row, col, box);
    }
};