// class Solution {
//   public:
//     int kthElement(vector<int> &a, vector<int> &b, int k) {
//         // code here
//         int i = 0;
//         int j = 0;
//         int n = a.size();
//         int m = b.size();
//         int x = 0;
//         while(i < n && j < m){
//             if(a[i] < b[j]){
//                 x++;
//                 if(x == k){
//                     return a[i];
//                 }
//                 i++;
//             }
//             else{
//                 x++;
//                 if(x == k){
//                     return b[j];
//                 }
//                 j++;  
//             } 
//         }
//         while(i < n){
//             if(x == k){
//                 return a[i];
//             }
//             i++;
//             x++;
//         }
//         while(j < m){
//             if(x == k){
//                 return b[j];
//             }
//             j++;
//             x++;
//         }
//         return 0;
//     }
// };

class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
       int n1 = a.size();
       int n2 = b.size();
       int n = n1 + n2;
       if(n1 > n2) return kthElement(b, a, k);
       int lo = max(k - n2, 0);
       int hi = min(k, n1);
       int left = k;
       while(lo <= hi){
           int mid1 = (lo + hi) >> 1;
           int mid2 = left - mid1;
           int l1 = INT_MIN;
           int l2 = INT_MIN;
           int r1 = INT_MAX;
           int r2 = INT_MAX;
           if(mid1 > 0) l1 = a[mid1 - 1];
           if(mid2 > 0) l2 = b[mid2 - 1];
           if(mid1 < n1) r1 = a[mid1];
           if(mid2 < n2) r2 = b[mid2];
           if(l1 <= r2 && l2 <= r1){
               return (max(l1, l2));
           }
           else if(l1 > r2) hi = mid1 - 1;
           else lo = mid1 + 1;
       }
       return 0;
    }
};