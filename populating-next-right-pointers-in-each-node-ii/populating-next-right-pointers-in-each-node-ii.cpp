class Solution {
public:
    Node* connect(Node* root) {
        if(!root){
            return root;
        }
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            Node *temp = nullptr;
            for(int i=0;i<size;i++){
                Node *top = q.front();
                q.pop();
                
                if(i == 0){
                    temp = top;
                }else{
                    temp->next = top;
                    temp = temp->next;
                }
                
                if(top->left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
            }
            if(temp){
                temp->next = nullptr;
            }
        }
        return root;
    }
};