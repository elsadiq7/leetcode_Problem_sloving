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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int counter = 0;
        vector<int> nums;

        while (head != nullptr) {
            nums.push_back(head->val);
            head = head->next;
        }
        ListNode dummay(0);
        ListNode* my_list = &dummay;
        for (int i = 0; i < nums.size(); i++) {
            if (nums.size() - i == n) {
                continue;
            }

            else {
                my_list->next = new ListNode(nums[i]);
                my_list = my_list->next;
            }
        }

        return dummay.next;
    }
};