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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1){
            return l2;
        }
        if(!l2){
            return l1;
        }
        int carry = 0;
        ListNode* head = l1;
        ListNode* prev = NULL;
        while(l1 && l2){
            l1->val += l2->val + carry;
            carry = l1->val / 10;
            l1->val %= 10;
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l2){
            prev->next = l2;
            l1 = l2;
        }
        if(!l1){
            if(carry){
                prev->next = new ListNode(carry);
            }
            return head;
        }
        while(l1){
            l1->val += carry;
            carry = l1->val / 10;
            l1->val %= 10;
            prev = l1;
            l1 = l1->next;
        }
        if(carry){
            prev->next = new ListNode(carry);
        }
        return head;
    }
};