class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum_array= accumulate(nums.begin(), nums.end(), 0); 
        int sum=0;
        
        for (int i=0;i<nums.size();i++)
         {
            if (sum==(sum_array-sum-nums.at(i)))
              return i;

            sum=sum+nums.at(i);
         }

         return -1;
    }
};