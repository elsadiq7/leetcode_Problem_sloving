//link: https://leetcode.com/problems/rotate-array/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        stack<int>st;
        k=k% nums.size();
        for (int i=0;i<nums.size();i++)
        {
           st.push(nums[i]); 
        }
        for (int i=k-1;i>-1;i--)
        {
            nums[i]=st.top();
            st.pop();
        }

        for (int i=nums.size()-1 ; i>=k;i--)
        {
            nums[i]=st.top();
            st.pop();
        }
    }
};