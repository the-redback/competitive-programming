#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string fraction = "";
        if (numerator < 0 ^ denominator < 0) fraction += "-";

        long dividend = labs(numerator);
        long divisor = labs(denominator);

        fraction += to_string(dividend / divisor);
        long remainder = dividend % divisor;

        if (remainder == 0) return fraction;

        fraction += ".";
        unordered_map<long, int> mp;
        while (remainder != 0) {
            if (mp.find(remainder) != mp.end()) {
                fraction.insert(mp[remainder], "(");
                fraction += ")";
                break;
            }
            mp[remainder] = fraction.size();
            remainder *= 10;
            fraction += to_string(remainder / divisor);
            remainder %= divisor;
        }

        return fraction;
    }
};