class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        // total cost and total gas 
        // 0 
        // total g
        // If the cost goes 
        int totalGas = 0;
        int totalCost = 0;
        int currentGas = 0;
        int startingIndex = 0;
        for (int i = 0; i < gas.size(); i++){

            totalGas += gas[i];
            totalCost += cost[i];

            currentGas += gas[i] - cost[i];

            if (currentGas < 0){
                startingIndex = i + 1;
                currentGas = 0;
            }
        }

        if (totalGas < totalCost){
            return -1;
        }

        return startingIndex;
        
    }
};