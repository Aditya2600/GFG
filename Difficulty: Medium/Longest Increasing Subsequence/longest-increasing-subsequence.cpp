class Solution {
  public:
    int lis(vector<int>& arr) {
        // code here
        vector<int> temp;
        int n = arr.size();
        temp.push_back(arr[0]);
        for(int i=1; i<n; i++){
            if(temp.back() < arr[i]){
                temp.push_back(arr[i]);
            }
            else{
                int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
                temp[ind] = arr[i];
            }
        }
        return temp.size();
    }
};