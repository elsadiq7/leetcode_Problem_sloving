class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long total_product = 1;
        int zero_count = 0;

        for (int num : nums) {
            if (num == 0) {
                zero_count++;
                continue;
            }
            total_product *= num;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (zero_count > 1) {
                nums[i] = 0;
            }
            else if (zero_count == 1) {
                nums[i] = (nums[i] == 0) ? total_product : 0;
            }
            else {
                nums[i] = total_product / nums[i];
            }
        }

        return nums;
    }
};

//link:https://leetcode.com/problems/product-of-array-except-self/?envType=study-plan-v2&envId=top-interview-150