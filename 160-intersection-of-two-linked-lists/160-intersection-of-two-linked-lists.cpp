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
    int getSize(ListNode* node){
        ListNode* curr = node;
        int res = 0;
        while(curr){
            res++;
            curr= curr->next;
        }
        return res;
    }
    ListNode * findIntersectionRec(ListNode *headA, ListNode *headB, int n, int m){
        if(n > m){
            return findIntersectionRec(headB, headA, m, n);
        }
        while(m > n){
            headB = headB->next;
            m--;
        }
        while(headA!=headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n = getSize(headA);
        int m = getSize(headB);
        return findIntersectionRec(headA, headB, n, m);
        // ListNode* temp1 = headA;
        // ListNode* temp2 = headB;
        // int ctr = 0;
        // while(temp1 != temp2){
        //     if(!temp1 || !temp2){
        //         ctr++;
        //     }
        //     if(ctr > 4){
        //         return NULL;
        //     }
        //     temp1 = temp1? temp1->next: headB;
        //     temp2 = temp2 ? temp2->next : headA;
        // }
        // return temp1;
    }
};