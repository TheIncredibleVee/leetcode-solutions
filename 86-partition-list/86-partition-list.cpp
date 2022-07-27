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
    ListNode* partition(ListNode* head, int x) {
        ListNode* node = head;
        ListNode* less = NULL;
        ListNode* more = NULL;
        ListNode* lessHead = NULL;
        ListNode* moreHead = NULL;
        while(node){
            ListNode* next = node->next;
            if(node->val < x){
                if(!less){
                    less = node;
                    lessHead = less;
                }else{
                    less->next = node;
                    less = less->next;
                }
            }else{
                if(!more){
                    more = node;
                    moreHead = node;
                }else{
                    more->next = node;
                    more = more->next;
                }
            }
            node = next;
        }
        if(less){
            less->next = moreHead;
            if(more) more->next = NULL;
            return lessHead;
        }else{
            return moreHead;
        }
    }
};