class Solution {
  public:
 
    int merge(vector<int> &arr, int lo, int mid, int hi){
        vector<int> temp;
        int left = lo;
        int right = mid + 1;
        int cnt = 0;
        while(left <= mid && right <= hi){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                cnt += (mid - left + 1);
                right++;
            }
        }
        while(left <= mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right <= hi){
            temp.push_back(arr[right]);
            right++;
        }
        for(int i=lo; i<=hi; i++){
            arr[i] = temp[i - lo];
        }
        return cnt;
    }
    
    int mergeSort(vector<int> &arr, int lo, int hi){
        int cnt = 0;
        if(lo >= hi) return cnt;
        int mid = lo + (hi - lo)/2;
        
        cnt += mergeSort(arr, lo, mid);
        cnt += mergeSort(arr, mid+1, hi);
        cnt += merge(arr, lo, mid, hi);
        return cnt;
    }
    int inversionCount(vector<int> &arr) {
        // Code Here
        return mergeSort(arr, 0, arr.size()-1);
        
    }
};