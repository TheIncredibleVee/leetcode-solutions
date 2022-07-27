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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1){
            return list2;
        }
        if(!list2){
            return list1;
        }
        if(list1->val > list2->val){
            swap(list1, list2);
        }
        ListNode* head = list1;
        while(list1->next && list2){
            if(list1->next->val > list2->val){
                ListNode* temp = list1->next;
                list1->next = list2;
                list2 = list2->next;
                list1->next->next = temp;
            }
            list1 = list1->next;
        }
        if(list2){
            list1->next = list2;
        }
        return head;
    }
    
    /*
        Alternate Approach using extra space to store the result
    */
    // ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        // ListNode* res = NULL;
        // ListNode* head = NULL; 
        // while(list1 && list2){
        //     if(list1->val < list2->val){
        //         if(!res){
        //             head = list1;
        //             res = list1;
        //         }else{
        //             res->next = list1;
        //             res = res->next;
        //         }
        //         list1 = list1->next;
        //     }else{
        //         if(!res){
        //             res = list2;
        //             head = list2;
        //         }else{
        //             res->next = list2;
        //             res = res->next;
        //         }
        //         list2 = list2->next;
        //     }
        // }
        // if(list1){
        //     res->next = list1;
        // }
        // if(list2){
        //     res->next = list2;
        // }
    // }
};