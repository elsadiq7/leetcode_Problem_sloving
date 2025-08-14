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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummay(0);
        ListNode * my_node=&dummay;
        map<int,int> hash;
        while(head!=nullptr)
        {
            hash[head->val]++;
            head=head->next;
        }
        
        for (auto & pair: hash)
        {
            if(pair.second==1)
            {
              my_node->next=new ListNode(pair.first);
              my_node=my_node->next;
            }

    
        }

        return dummay.next;
    }
};