class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int max_normal = maxSubArray(nums); // max sum without wrapping
        int min_sub =
            minSubArray(nums); // min sum to subtract for circular case

        int total_sum = 0;
        for (int num : nums)
            total_sum += num;

        if (max_normal < 0)
            return max_normal;

        // Maximum of normal max and circular max
        return max(max_normal, total_sum - min_sub);
    }

    // Standard Kadane's algorithm to find max subarray sum
    int maxSubArray(vector<int>& nums) {
        int max_current = nums[0];
        int max_end = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            max_current = max(nums[i], max_current + nums[i]);
            max_end = max(max_end, max_current);
        }

        return max_end;
    }

    // Similar to Kadane's but finds minimum subarray sum
    int minSubArray(vector<int>& nums) {
        int min_current = nums[0];
        int min_end = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            min_current = min(nums[i], min_current + nums[i]);
            min_end = min(min_end, min_current);
        }

        return min_end;
    }
};