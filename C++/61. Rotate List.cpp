/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k==0 || head==nullptr)  return head;

        vector<int> nums;
        while (head != nullptr) {
            nums.push_back(head->val);
            head = head->next;
        }

        ListNode dummy(0);
        ListNode* my_node = &dummy;

        k = k % nums.size();

        int mid = nums.size() - k ;
         for (int i = mid; i < nums.size(); i++) {
            my_node->next = new ListNode(nums[i]);
            my_node = my_node->next;
        }

        for (int i = 0; i < mid; i++) {
            my_node->next = new ListNode(nums[i]);
            my_node = my_node->next;
        }

        return dummy.next;
    }
};