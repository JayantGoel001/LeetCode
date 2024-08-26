class Solution {
public:
    void order(Node *root,vector<int> &v){
        if(root){
            for(auto it : root->children){
                order(it,v);
            }
            v.push_back(root->val);
        }
    }
    vector<int> postorder(Node* root) {
        vector<int> v;
        order(root,v);
        return v;
    }
};