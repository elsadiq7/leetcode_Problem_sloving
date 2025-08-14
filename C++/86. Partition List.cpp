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
    ListNode* partition(ListNode* head, int x) {

        if (head == nullptr)
            return head;

        ListNode dummy(0);
        dummy.next=head;

        vector<int> nums;
        while (head != nullptr) {

            nums.push_back(head->val);
            head = head->next;
        }

        head=dummy.next;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < x) {

                head->val=nums[i];
                head=head->next;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= x) {

                head->val=nums[i];
                head=head->next;
            }
        }

        return dummy.next;

    }
};