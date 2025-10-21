class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int> pq;
        int n = arr.size();
        for(int i=0; i<n; i++){
            pq.push(arr[i]);
            if(pq.size() > k){
                pq.pop();
            }
        }
        return pq.top();
    }
};