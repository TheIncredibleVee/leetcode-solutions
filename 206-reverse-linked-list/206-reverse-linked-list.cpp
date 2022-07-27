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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* res = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return res;
        ListNode* node = head;
        ListNode* prev = NULL; 
        while(node){
            ListNode* temp = node->next;
            node->next = prev;
            prev = node;
            node = temp;
        }
        return prev;
    }
    
    /*
        Alternate Approach Using Extra Space O(n) of stack
    */
    // ListNode* reverseList(ListNode* head) {
    //     if(!head || !head->next){
    //         return head;
    //     }
    //     ListNode* res = NULL;
    //     stack<ListNode*> st;
    //     while(head){
    //         st.push(head);
    //         head = head->next;
    //     }
    //     res = st.top();
    //     st.pop();
    //     ListNode* node = res;
    //     while(!st.empty()){
    //         node->next = st.top();
    //         node = node->next;
    //         st.pop();
    //     }
    //     node->next = NULL;
    //     return res;
    // }

};