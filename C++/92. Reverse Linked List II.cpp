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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right)
          return head;

        ListNode* reverse = head;

        int counter = 1;
        vector<int> array;

        while (reverse != nullptr) {

            if (counter >= left && counter <= right) {
                array.push_back(reverse->val);
            } 

            reverse = reverse->next;
            counter++;
        }
        counter = 1;
        reverse = head;
        int i=0;

         while (reverse != nullptr) {

            if (counter >= left && counter <= right) {
                reverse->val= array[right-left-i];
                i++;
            } 

            reverse = reverse->next;
            counter++;
        }

        return head;
    }
};