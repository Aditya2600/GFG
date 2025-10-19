class Solution {
  public:
    long long pow(int a, int b){
        int res = 1;
        while(b){
            if(b & 1){
                res = res * a;
            }
            a = a * a;
            b >>= 1;
        }
        return res;
    }
    int nthRoot(int n, int m) {
        // Code here
        for(int i=1; i<=m; i++){
            long long val = pow(i, n);
            if((int)val == m) return i;
            else if(val > m) break;
        }
        return -1;
    }
};