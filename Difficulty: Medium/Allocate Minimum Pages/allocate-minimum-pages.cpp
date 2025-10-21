// class Solution {
//   public:
//     int f(vector<int> &arr, int pages){
//         int stu = 1;
//         int pagesStudent = 0;
//         int n = arr.size();
//         for(int i=0; i<n; i++){
//             if(pagesStudent + arr[i] <= pages){
//                 pagesStudent += arr[i];
//             }
//             else{
//                 stu++;
//                 pagesStudent = arr[i];
//             }
//         }
//         return stu;
//     }
//     int findPages(vector<int> &arr, int k) {
        
//         int maxarr = INT_MIN;
//         int n = arr.size();
//         if(k > n) return -1;
//         int sum = 0;
//         for(int i=0; i<n; i++){
//             maxarr = max(arr[i], maxarr);
//             sum += arr[i];
//         }
//         int low = maxarr;
//         int hi = sum;
//         for(int pages = low; pages <= hi; pages++){
//             int cntStu = f(arr, pages);
//             if(cntStu == k){
//                 return pages;
//             }
//         }
//         return -1;
//     }
// };

class Solution {
  public:
    int f(vector<int> &arr, int pages){
        int stu = 1;
        int pagesStudent = 0;
        int n = arr.size();
        for(int i=0; i<n; i++){
            if(pagesStudent + arr[i] <= pages){
                pagesStudent += arr[i];
            }
            else{
                stu++;
                pagesStudent = arr[i];
            }
        }
        return stu;
    }
    int findPages(vector<int> &arr, int k) {
        
        int maxarr = INT_MIN;
        int n = arr.size();
        if(k > n) return -1;
        int sum = 0;
        for(int i=0; i<n; i++){
            maxarr = max(arr[i], maxarr);
            sum += arr[i];
        }
        int lo = maxarr;
        int hi = sum;
        
        while(lo <= hi){
            int mid = (lo + hi) >> 1;
            int noStu = f(arr, mid);
            if(noStu > k){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return lo;
    }
};