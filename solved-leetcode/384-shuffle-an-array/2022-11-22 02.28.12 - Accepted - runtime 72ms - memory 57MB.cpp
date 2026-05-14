#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
private:
    vector<int> original;
    vector<int> sf;

public:
    Solution(vector<int>& nums) {
        srand(time(NULL));
        original = nums;
        sf = nums;
    }

    vector<int> reset() { return original; }

    vector<int> shuffle() {
        for (int i = sf.size() - 1; i >= 0; i--) {
            int in = rand() % (i + 1);
            int temp = sf[in];
            sf[in] = sf[i];
            sf[i] = temp;
        }
        return sf;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */