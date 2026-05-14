class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {        

        int totalCost = 0;
        int onBoard = 0;
        int start = 0;
        
        for(int i = 0; i<gas.size(); i++){
            int diff = gas[i] - cost[i];
            totalCost += diff;
            onBoard += diff;

            if(onBoard <0 ){
                onBoard = 0;
                start = i+1;
            }


        }

        if(totalCost < 0)
            return -1;

        return start;
    }
};