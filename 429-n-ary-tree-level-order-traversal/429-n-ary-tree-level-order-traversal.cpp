class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> v;
        if(root){
            queue<Node *> q;
            q.push(root);

            while(!q.empty()){
                vector<int> v2;
                int size = q.size();
                for(int i=0;i<size;i++){
                    Node *temp = q.front();
                    q.pop();
                    v2.push_back(temp->val);
                    
                    for(auto it : temp->children){
                        q.push(it);
                    }
                }
                v.push_back(v2);
            }
        }
        return v;
    }
};