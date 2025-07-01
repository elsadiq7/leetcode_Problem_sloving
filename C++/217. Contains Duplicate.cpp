class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            unordered_map<int,int> hashmap;
            for (int i:nums)
            {
                if (hashmap.count(i))
                    return true;
                else
                   hashmap[i]=1;
            }
            return false;
        }
    };