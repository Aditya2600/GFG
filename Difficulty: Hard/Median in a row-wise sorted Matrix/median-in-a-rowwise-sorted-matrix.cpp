class Solution {
  public:
    int upper_bound(vector<int>& mat, int x, int m){
        int lo = 0;
        int hi = m - 1;
        int ans = m;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(mat[mid] > x){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return ans;
    }
    int countSmallEqual(vector<vector<int>> &matrix, int n, int m, int x){
        int cnt = 0;
        for(int i=0; i<n; i++){
            cnt += upper_bound(matrix[i], x, m);
        }
        return cnt;
    }
    int median(vector<vector<int>> &mat) {
        // code here
        int low = INT_MAX, high = INT_MIN;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0; i<n; i++){
            low = min(low, mat[i][0]);
            high = max(high, mat[i][m-1]);
        }
        int req = (n*m)/2;
        while(low <= high){
            int mid = low + (high - low)/2;
            int smallEqual = countSmallEqual(mat, n, m, mid);
            if(smallEqual <= req) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};
