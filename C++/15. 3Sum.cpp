class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> threesum;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicates

            vector<vector<int>> pairs = twoSum(nums, -nums[i], i + 1);
            for (auto& pair : pairs) {
                threesum.push_back({nums[i], pair[0], pair[1]});
            }
        }
        return threesum;
    }

    vector<vector<int>> twoSum(vector<int>& nums, int target, int start) {
        int left = start;
        int right = nums.size() - 1;
        vector<vector<int>> results;

        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                results.push_back({nums[left], nums[right]});
                left++;
                right--;

                while (left < right && nums[left] == nums[left - 1]) left++;
                while (left < right && nums[right] == nums[right + 1]) right--;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return results;
    }
};
