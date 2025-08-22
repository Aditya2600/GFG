class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int n = arr.size();
        int mid = 0;
        int low = 0;
        int hi = n-1;
        while(mid <= hi){
            if(arr[mid] == 0){
                swap(arr[mid], arr[low]);
                low++;
                mid++;
            }
            else if(arr[mid] == 1){
                mid++;
            }
            else{
                swap(arr[mid], arr[hi]);
                hi--;
            }
        }
    }
};