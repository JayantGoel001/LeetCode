class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return nullptr;
        }
        Node *curr = head;
        while(curr){
            Node *temp = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = temp;
            curr = temp;
        }
        
        curr = head;
        while(curr){
            if(curr->next){
                curr->next->random = curr->random ? curr->random->next : nullptr; 
            }
            curr = curr->next ? curr->next->next : nullptr;
        }
        
        Node *org = head;
        Node *copy = head->next;
        Node *cHead = copy;
        
        while(org && copy){
            org->next = org->next ? org->next->next : nullptr;
            copy->next = copy->next ? copy->next->next : nullptr;
            
            org = org->next;
            copy = copy->next;
        }
        
        return cHead;
    }
};