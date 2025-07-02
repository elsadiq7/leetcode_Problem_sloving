class Solution {
public:
    int jump(vector<int>& nums) {
         int counter=0;
         int max_reach=0;
         int our_reach=0;
        for (int i=0;i<nums.size()-1;i++)
        {  

            max_reach=max(max_reach,i+nums[i]);
            if (i==our_reach)
            {
                counter++;
                our_reach=max_reach;
            }

        }
        return counter;
    }
};

//link:https://leetcode.com/problems/jump-game-ii/?envType=study-plan-v2&envId=top-interview-150