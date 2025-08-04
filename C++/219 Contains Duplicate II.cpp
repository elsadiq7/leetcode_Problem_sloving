class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>  hash;
        int key;
        for (int i=0;i<nums.size();i++)
        {   
            key=nums[i];
            if (!hash.count(key))
            {
                hash[key]=i;
            }
            else if ( abs(hash[key]-i)<=k)
              return true;
            else 
               hash[key]=i;
        }

        return false;
        
    }
};