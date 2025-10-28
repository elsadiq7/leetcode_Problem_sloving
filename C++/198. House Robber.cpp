class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];

        int prev2 = nums[0];
        int prev = max(nums[0], nums[1]);
        int current;
        for (int i = 2; i < nums.size(); i++) {
            current = max(prev, nums[i] + prev2);
            prev2 = prev;
            prev = current;
        }
        return prev;
    }
};


