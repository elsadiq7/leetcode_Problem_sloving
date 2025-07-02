//link:https://leetcode.com/problems/majority-element/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = nums.size() / 2;
        int num = 0;
        unordered_map<int, int> hash_map;
        for (int i = 0; i < nums.size(); i++) {
            hash_map[nums[i]]++;
            if (hash_map[nums[i]] > major) {
                num = nums[i];
                break;
            }
        }
        return num;
    }
};