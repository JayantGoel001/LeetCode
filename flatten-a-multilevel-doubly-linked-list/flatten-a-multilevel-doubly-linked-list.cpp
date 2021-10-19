/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node *temp = head;
        while(temp){
            if(temp->child){
                Node *next = temp->next;
                
                Node *child = temp->child;
                
                child->prev = temp;
                temp->next = child;
                
                temp->child = nullptr;
                
                Node *temp2 = child;
                while(temp2->next){
                    temp2 = temp2->next;
                }
                temp2->next = next;
                if(next){
                    next->prev = temp2;
                }
            }
            temp = temp->next;
        }
        
        return head;
    }
};