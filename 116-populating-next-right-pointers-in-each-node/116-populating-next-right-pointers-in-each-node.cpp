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
            Node *temp = new Node(0);
            while(size--){
                Node *top = q.front();
                q.pop();
                
                temp->next = top;
                temp = temp->next;
                
                if(top->left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
            }
        }
        return root;
    }
};