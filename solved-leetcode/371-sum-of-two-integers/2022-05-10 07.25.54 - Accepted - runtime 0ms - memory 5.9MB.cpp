class Solution {
public:
    int getSum(int a, int b) {
         while (b != 0) {
            int temp = a ^ b;
            unsigned carry = a & b;
            a = temp;
            b = carry << 1;
        }
        
        return a;
    }
};