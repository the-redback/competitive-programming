class Solution {
    bool isEnough(int x, int m, int n, int k){
        int count=0;
        for(int i=1; i<=m ; i++){
            count += min(x/i, n);
        }
        return count >= k;
    }
public:
    int findKthNumber(int m, int n, int k) {
        int lo=1, hi=m*n;
        while(lo < hi){
            int mid = (lo + hi)/2;
            if(isEnough(mid, m, n, k)) hi=mid;
            else lo = mid+1;
        }
        return lo;
    }
};