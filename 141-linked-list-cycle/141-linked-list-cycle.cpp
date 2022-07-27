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
        ListNode* fast = head;
        ListNode* slow = head;
        if(!head || !head->next){
            return false;
        }
        do{
            fast = fast->next->next;
            slow = slow->next;
        }while(slow && fast && fast->next && slow != fast);
        if(fast == slow){
            return true;
        }else{
            return false;
        }
    }
};