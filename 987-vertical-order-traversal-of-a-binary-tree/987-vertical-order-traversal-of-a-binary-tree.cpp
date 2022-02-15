class Solution {
public:
    
    static bool cmp(pair<int,int> p1,pair<int,int> p2){
        return (p1.second == p2.second) ? (p1.first < p2.first) : (p1.second < p2.second);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode *,int>> q;
        
        unordered_map<int,vector<pair<int,int>>> mp;
        int mini = INT_MAX;
        q.push({root,0});
        
        int h = 0;
        
        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                pair<TreeNode *,int> top = q.front();
                q.pop();
                
                mp[top.second].push_back({top.first->val,h});
                mini = min(mini,top.second);
                
                if(top.first->left){
                    q.push({top.first->left,top.second-1});
                }
                if(top.first->right){
                    q.push({top.first->right,top.second+1});
                }
            }
            h++;
        }
        vector<vector<int>> v;
        while(mp.find(mini)!=mp.end()){
            sort(mp[mini].begin(),mp[mini].end(),cmp);
            v.push_back(vector<int> ());
            for(auto it : mp[mini]){
                v.back().push_back(it.first);
            }
            mini++;
        }
        return v;
    }
};