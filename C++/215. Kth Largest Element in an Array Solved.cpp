
class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            priority_queue<int> pre_queue;
            for (int i:nums)
            {
                pre_queue.push(i);
            }
            for (int i=0;i<k-1;i++)
            {
                pre_queue.pop();
            }
    
            return pre_queue.top();
        }
    };