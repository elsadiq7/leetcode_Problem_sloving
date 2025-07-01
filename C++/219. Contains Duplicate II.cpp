class Solution {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            unordered_map<int, int> hashmap;
            bool exist;
            for (int i = 0; i < nums.size(); i++) {
                exist = hashmap.count(nums[i]);
                if (exist && abs(hashmap[nums[i]]-i)<= k)  {
                    return true;
                }
                hashmap[nums[i]] = i;
            }
            return false;
        }
    };