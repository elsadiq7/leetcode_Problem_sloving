class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
        }

        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (hash[nums[i]] > 0 && hash[k - nums[i]] > 0 &&
                ((nums[i] != k - nums[i]) ||
                 (nums[i] == k - nums[i] && hash[nums[i]] > 1))) {

                hash[nums[i]]--;
                hash[k - nums[i]]--;
                count++;
            }
        }
        return count;
    }
};