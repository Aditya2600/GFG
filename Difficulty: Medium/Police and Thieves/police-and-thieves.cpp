class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        int p = 0, t = 0;
        int n = arr.size();
        while(p<n && arr[p] != 'P') p++;
        while(t<n && arr[t] != 'T') t++;
        int count = 0;
        while(p < n && t < n){
            if(abs(p - t) <= k){
                count++;
                p++;
                t++;
            }
            else if(p < n && p < t){
                p++;
            }
            else if(t < n && t < p){
                t++;
            }
            while(p<n && arr[p] != 'P') p++;
            while(t<n && arr[t] != 'T') t++;
        }
        return count;
    }
};