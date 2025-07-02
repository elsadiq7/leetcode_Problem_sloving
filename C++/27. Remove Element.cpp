//link: https://leetcode.com/problems/remove-element/
// LeetCode problem number: 27
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size=nums.size();
        int counter=0;
        for (int i=0;i<size;i++)
        {
            if (nums[i]!=val)
            {   
                nums[counter]=nums[i];
                counter++;
            }
        }

        return counter;

   

       
    }
};