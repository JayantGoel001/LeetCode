class Solution {
public:
    unordered_map<Node*,Node*> mp;
    Node* cloneGraph(Node* node) {
        if(!node){
            return nullptr;
        }
        Node *copy = new Node(node->val);
        mp[node] = copy;
        
        for(auto it : node->neighbors){
            if(mp[it]){
                copy->neighbors.push_back(mp[it]);
            }else{
                copy->neighbors.push_back(cloneGraph(it));
            }
        }
        return copy;
    }
};