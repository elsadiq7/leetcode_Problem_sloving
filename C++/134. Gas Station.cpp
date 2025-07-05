class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int tank = 0;
        int start = 0;

        for (int i = 0; i < gas.size(); i++) {
            int diff = gas[i] - cost[i];
            sum += diff;
            tank += diff;

            // If tank goes negative, we can't start from here or any before
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }

        return (sum < 0) ? -1 : start;
    }
};
