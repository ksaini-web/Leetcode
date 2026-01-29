/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode* show = head;
        ListNode* fast = head;

        while(fast!=NULL and fast->next != NULL){

            show = show->next;
            fast = fast->next->next;

            if(fast == show){

                return true;
            } 
        }
        return false;
        
    }
};
