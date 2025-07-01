class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            unordered_map<int, int> hash_map;
    
            int num;
    
            for (int i = 0; i < nums.size(); i++) {
                if (hash_map.count(nums[i])) {
                    num = nums[i];
                    break;
                }
    
                hash_map[nums[i]] = 1;
            }
            return num;
        }
    };
    
    