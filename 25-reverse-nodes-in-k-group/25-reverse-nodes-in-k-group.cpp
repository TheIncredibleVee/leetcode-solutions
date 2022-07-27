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
    ListNode* getAhead(ListNode* root, int k){
        ListNode* node = root;

        while(node && k--){
            node = node->next;
        }
        return node;
    }
    int getSize(ListNode* head){
        int res = 0;
        while(head){
            head = head->next;
            res++;
        }
        return res;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next || getSize(head) < k){
            return head;
        }
        ListNode* root = head;
        ListNode* prev = NULL;
        int num = k;
        while(root && num--){
            ListNode* next = root->next;
            root->next = prev;   
            prev = root;
            root = next;
        }
        ListNode* rest = reverseKGroup(root, k);
        head->next = rest;
        return prev;
        
        
        // int num;
        // while(root){
        //     num = k;
        //     prev = NULL;
        //     while(root && num--){
        //         ListNode* next = root->next;
        //         if(!prev){
        //             root->next = getAhead(root, k);
        //         }else{
        //             root->next = prev;   
        //         }
        //         prev = root;
        //         root = next;
        //     }
        //     if(!res){
        //         res = prev;
        //     }
        // }
        // return res;
    }
};