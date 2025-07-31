#include <vector>
#include <unordered_set>

class Solution {
public:
    int subarrayBitwiseORs(std::vector<int>& arr) {
        // This set will store all unique OR values found across all subarrays.
        std::unordered_set<int> result_ors;
        
        // This set stores the distinct ORs of all subarrays ending at the previous position.
        std::unordered_set<int> current_ors;

        for (int x : arr) {
            // `next_ors` will store the ORs of subarrays ending at the current element `x`.
            std::unordered_set<int> next_ors;
            
            // The subarray of just the element x gives an OR of x.
            next_ors.insert(x);

            // Compute new ORs by extending previous subarrays with the current element x.
            for (int y : current_ors) {
                next_ors.insert(x | y);
            }

            // Add all newly found ORs to the main result set.
            result_ors.insert(next_ors.begin(), next_ors.end());
            
            // For the next iteration, the current results become the previous results.
            current_ors = next_ors;
        }

        return result_ors.size();
    }
};