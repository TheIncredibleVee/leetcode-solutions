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
private:
    ListNode* reverse(ListNode* head, ListNode* prev){
        if(!head || !head->next){
            return head;
        }
        ListNode* restHead = reverse(head->next, head);
        head->next->next = head;
        head->next = prev;
        return restHead;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = NULL;
        if(!head || !head->next){
            return true;
        }
        do{
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }while(fast && fast->next);
        if(!fast){
            prev->next = reverse(slow, NULL);
            prev = prev->next;
        }else{
            slow->next = reverse(slow->next,NULL);
            prev = slow->next;
        }
        while(prev){
            if(head->val != prev->val){
                return false;
            }
            prev = prev->next;
            head = head->next;
        }
        return true;
    }
};