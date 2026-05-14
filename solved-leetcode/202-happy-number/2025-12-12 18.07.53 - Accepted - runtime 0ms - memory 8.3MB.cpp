class Solution {
public:
    int nextNumber(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            n = n / 10;
            sum += digit * digit;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> seen;

        while (n != 1) {
            int next = nextNumber(n);
            if (seen.find(next) != seen.end()) return false;
            seen.insert(next);
            n = next;
        }
        return true;
    }
};