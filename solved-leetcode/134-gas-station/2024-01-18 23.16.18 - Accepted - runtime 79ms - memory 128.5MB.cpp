#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int totalCost = 0;
        int onBoard = 0;
        int start = 0;

        for (int i = 0; i < gas.size(); i++) {
            int diff = gas[i] - cost[i];
            totalCost += diff;
            onBoard += diff;

            if (onBoard < 0) {
                onBoard = 0;
                start = i + 1;
            }
        }

        return totalCost < 0 ? -1 : start;
    }
};