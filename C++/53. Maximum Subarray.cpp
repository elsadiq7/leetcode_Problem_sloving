class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_current = nums[0];
        int max_end = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            max_current = max(nums[i], max_current + nums[i]);
            max_end = max(max_end, max_current);
        }

        return max_end;
    }
};