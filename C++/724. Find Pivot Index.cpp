class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> sumLeft(nums.size(), 0);
        vector<int> sumRight(nums.size(), 0);

        for (int i = 1; i < nums.size(); i++) {
            sumLeft[i] = sumLeft[i - 1] + nums[i-1];
        }
        for (int i = nums.size() - 2; i > -1; i--) {
            sumRight[i] = sumRight[i + 1] + nums[i+1];
        }

        for(int i=0;i<nums.size();i++)
        {
            if(sumLeft[i]==sumRight[i])
            {
                return i;
            }
        }
        return -1;
    }
};

/*
















*/