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
    int getSize(ListNode* head){
        int res = 0;
        while(head){
            head= head->next;
            res++;
        }
        return res;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int n = getSize(head);
        if(n <= 0){
            return head;
        }
        k %= n;
        if(k <= 0){
            return head;
        }
        int num = k;
        ListNode* fast = head;
        ListNode* slow = head;
        while(num--){
            fast = fast->next;
        }
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* res = slow->next;
        slow->next = NULL;
        fast = res;
        while(fast->next){
            fast = fast->next;
        }
        fast->next = head;
        return res;
    }
};