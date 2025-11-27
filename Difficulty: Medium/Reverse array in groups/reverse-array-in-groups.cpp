class Solution {
  public:
  
  void rev(int l, int r, vector<int> &arr){
      while(l < r){
          swap(arr[l], arr[r]);
          l++;
          r--;
      }
  }
    void reverseInGroups(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        int i = 0;
        
        while(i < n){
            int j = i + k - 1;
            if(j >= n){
                j = n - 1;
            }
            rev(i, j, arr);
            i = j + 1;
        }
    }
};
