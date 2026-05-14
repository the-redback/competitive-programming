class Solution {
public:
    int countPrimes(int n) {
        vector<int>p(n+1);
        for(int i=2;i*i<=n;i++){
            if(p[i]==0){
                for(int j=i*i;j<=n;j+=i)
                {
                    p[j]=1;
                }
            }
        }
        int cnt=0;
        for(int i=2;i<n;i++){
            if(!p[i]) cnt++;
        }
        return cnt;
    }
};