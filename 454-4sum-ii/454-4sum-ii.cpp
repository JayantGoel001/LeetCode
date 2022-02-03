#define ll long long int
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        vector<ll> v1;
        for(auto it1 : nums1){
            for(auto it2 : nums2){
                v1.push_back((ll)it1+(ll)it2);
            }
        }
        vector<ll> v2;
        for(auto it3 : nums3){
            for(auto it4 : nums4){
                v2.push_back((ll)it3 + (ll)it4);
            }
        }
        
        unordered_map<ll,int> mp;
        int count = 0;
        
        for(auto it1 : v1){
            mp[it1]++;
        }
        for(auto it2 : v2){
            count += mp[-it2];
        }
        return count;
    }
};