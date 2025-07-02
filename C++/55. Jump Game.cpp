class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reach=0;

        for (int i=0;i<nums.size();i++)
        {  
            if (i>max_reach)
              return false;
          max_reach=max(max_reach,i+nums[i]);
        }
        return true;
    }
};

//link:https://leetcode.com/problems/jump-game/?envType=study-plan-v2&envId=top-interview-150   