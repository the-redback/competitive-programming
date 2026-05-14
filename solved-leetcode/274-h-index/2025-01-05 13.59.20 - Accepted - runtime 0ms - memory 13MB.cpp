#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> citeBucket(n + 1, 0);

        for (auto val : citations) {
            citeBucket[min(val, n)]++;
        }

        // hindex is h if h number of papers have atleast h citation
        int sumPapers = 0;
        for (int h = n; h >= 0; h--) {
            sumPapers += citeBucket[h];

            if (sumPapers >= h) return h;
        }

        return 0;
    }
};