class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> nums;
        ListNode* node = head;

        while (node != nullptr) {
            nums.push_back(node->val);
            node = node->next;
        }
        node = head;
        int n = nums.size();
        for (int i = 0; i + k <= n; i += k) {
            for (int j = i + k - 1; j >= i; j--) {
                node->val = nums[j];
                node = node->next;
            }
        }

        return head;
    }
};