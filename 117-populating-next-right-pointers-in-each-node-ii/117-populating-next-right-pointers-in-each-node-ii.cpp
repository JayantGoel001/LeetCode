class Solution {
public:
    Node* connect(Node* root) {
        if(!root){
            return root;
        }
        Node *head = nullptr;
        Node *temp = root;
        Node *prev = nullptr;
        while(temp){
            while(temp){
                if(temp->left){
                    if(prev){
                        prev->next = temp->left;
                    }else{
                        head = temp->left;
                    }
                    prev = temp->left;
                }
                if(temp->right){
                    if(prev){
                        prev->next = temp->right;
                    }else{
                        head = temp->right;
                    }
                    prev = temp->right;
                }
                temp = temp->next;
            }
            temp = head;
            head = nullptr;
            prev = nullptr;
        }
        
        return root;
    }
};