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
    ListNode* sortList(ListNode* head) {
        // ✅ Correct base case
        if (!head || !head->next)
            return head;

        // Step 1: Split the list into two halves
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Cut the list
        ListNode* mid = slow->next;
        slow->next = nullptr;

        // Step 3: Sort each half
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        // Step 4: Merge sorted halves
        return merge(left, right);
    }

private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;  
        }

        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};




//////////////////////////////////////////////////////////////////




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
    ListNode* sortList(ListNode* head) {
        if (!head) return nullptr;

        vector<int> nums;
        ListNode* temp = head;
        while (temp != nullptr) {
            nums.push_back(temp->val);
            temp = temp->next;
        }

        sort(nums.begin(), nums.end());

        ListNode* curr = head;
        for (int val : nums) {
            curr->next = new ListNode(val);
            curr = curr->next;
        }

        return head->next;
    }
};

