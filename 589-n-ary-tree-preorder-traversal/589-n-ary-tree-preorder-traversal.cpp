class Solution {
public:
    vector<int> v;
    
    void preOrder(Node *root){
        if(root){
            v.push_back(root->val);
            for(auto it : root->children){
                preOrder(it);
            }
        }
    }
    
    vector<int> preorder(Node* root) {
        preOrder(root);
        
        return v;
    }
};