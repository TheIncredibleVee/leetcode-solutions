/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return NULL;
        }
        // if(!head->next){
        //     Node* copy = new Node(head->val);
        //     copy->random = head->random;
        //     return copy;
        // }
        Node* curr = head;
        while(curr){
            Node* nxt = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = nxt;
            curr = nxt;
        }
        curr = head;
        while(curr){
            curr->next->random = curr->random ? curr->random->next : NULL;
            curr = curr->next->next;
        }
        Node* resHead = NULL;
        Node* res = NULL;
        curr = head;
        while(curr){
            Node* nxt = curr->next->next;
            if(!res){
                res = curr->next;
                resHead = curr->next;
            }else{
                res->next = curr->next;
                res = res->next;
            }
            curr->next = nxt;
            curr = nxt;
        }
        curr = head;
        res->next = NULL;
        return resHead;
    }
};