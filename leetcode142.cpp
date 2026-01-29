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
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* show = head;
        ListNode* fast = head;
       bool iscycle=false;

        while(fast!=NULL and fast->next!= NULL){

            show = show->next;
            fast = fast->next->next;
         if(show==fast){
            iscycle=true;
            break;}

        }
        if(!iscycle){
            return NULL;
        }
        show=head;

        while(show != fast){
           show= show->next;
            fast=fast->next;

           
        }
         return show;
    }
};
