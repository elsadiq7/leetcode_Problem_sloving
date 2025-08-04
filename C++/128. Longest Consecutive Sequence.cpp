class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        int current_counter=1;
        int max_counter=1;
        for (int i=1;i<nums.size();i++)
        {
             if (nums[i]==nums[i-1]+1)
               current_counter++;
             else if (nums[i]==nums[i-1])
                continue;
            else 
            {   
                current_counter=1;
            }

            max_counter=max(max_counter,current_counter);

        }
        return max_counter;
    }
};