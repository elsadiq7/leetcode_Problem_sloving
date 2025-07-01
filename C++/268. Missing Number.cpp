class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            int max=nums[0];
            int sum=0;
            int mid;
            for (int i=0;i<nums.size();i++)
            {     
                  mid=nums[i];
                  if (mid>max)
                   max=mid;
    
                  sum+=mid;
            }
    
            int total_sum=(nums.size())*(nums.size()+1)/2;
    
            return total_sum-sum;
            
        }
    };