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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        vector<int> prices;
        ListNode *temp = head;
        while (temp != nullptr) {
            prices.push_back(temp->val);
            temp = temp->next;
        }

        int size = prices.size();
        temp = head;
        for (int i = 0; i < size / 2; i++) {
            temp->val = prices[i];
            temp = temp->next;
            temp->val = prices[size - i - 1];
            temp = temp->next;
        }

        if (size % 2 != 0) {
            temp->val = prices[size / 2];
            temp->next = nullptr;
        }
    }
};