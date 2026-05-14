class Solution {
public:
    int reverse(int x) {
        int reverse_num = 0;

        while (x != 0) {
            int pop = x % 10;
            x /= 10;

            if (reverse_num > INT_MAX / 10 || (reverse_num == INT_MAX / 10 && pop > INT_MAX % 10)) {
                return 0;
            }
            if (reverse_num < INT_MIN / 10 || (reverse_num == INT_MIN / 10 && pop < INT_MIN % 10)) {
                return 0;
            }

            reverse_num *= 10;
            reverse_num += pop;
        }
        return reverse_num;
    }
};