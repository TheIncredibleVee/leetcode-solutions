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
        if(right <= left){
            return head;
        }
        ListNode * node = head;
        ListNode* prev = NULL;
        bool flag = false;
        int l = left;
        while(--l){
            flag = true;
            prev = node;
            node = node->next;
        }
        ListNode* last = NULL;
        int sz = right - left + 1;
        ListNode* root = node;
        while(node && sz--){
            ListNode* next = node->next;
            node->next = last;
            last = node;
            node = next;
        }
        root->next = node;
        if(flag){
            prev->next = last;
        }else{
            head = last;
        }
        return head;
    }
};