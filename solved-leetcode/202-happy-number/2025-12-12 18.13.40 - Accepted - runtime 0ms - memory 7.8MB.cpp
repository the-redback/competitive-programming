class Solution {
public:
    int nextNumber(int n){
        int sum = 0;
        while(n>0){
            int digit = n%10;
            n = n/10;
            sum += digit * digit;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slowRunner = n;
        int fastRunner = nextNumber(n);

        while(fastRunner != 1 && slowRunner != fastRunner){
            slowRunner = nextNumber(slowRunner);
            fastRunner = nextNumber(nextNumber(fastRunner));
        }    

        return fastRunner == 1;
    }
};