class Solution {
public:
    unordered_map<int,Node*> v;
    Node* cloneGraph(Node* node) {
        if(!node){
            return nullptr;
        }
        v[node->val] = new Node(node->val);
        
        for(auto it : node->neighbors){
            if(!v[it->val]){
                v[node->val]->neighbors.push_back(cloneGraph(it));
            }else{
                v[node->val]->neighbors.push_back(v[it->val]);
            }
        }
        return v[node->val];
    }
};