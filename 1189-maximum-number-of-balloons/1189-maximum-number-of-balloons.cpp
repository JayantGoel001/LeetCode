class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> v(26, 0);
        for(auto it : text){
            v[it - 'a']++;
        }
        int maxi = INT_MAX;
        maxi = min(maxi, v[1]);
        maxi = min(maxi, v[0]);
        maxi = min(maxi, v['l' - 'a']/2);
        maxi = min(maxi, v['o' - 'a']/2);
        maxi = min(maxi, v['n' - 'a']);
        
        return maxi;
    }
};