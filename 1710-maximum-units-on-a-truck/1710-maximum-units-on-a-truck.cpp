class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<int> buckets(1001, -1);
        int space_remaining_boxes = truckSize;
        int units_loaded = 0;
        for (int i = 0; i < boxTypes.size(); ++i) {
            if (buckets[ boxTypes[i][1] ] == -1) {
                buckets[ boxTypes[i][1] ] = boxTypes[i][0];
            } else { // already has a value
                buckets[ boxTypes[i][1] ] += boxTypes[i][0];
            }
            
            // optimization idea: when populating, track the highest and lowest boxesperunit for use as indices below
        }
        
        for (int i = 1000; i >= 0; --i) {
            if (buckets[i] == -1) continue;
            
            if (buckets[i] > space_remaining_boxes) { // case:not enough space on truck. eg., we have 2 box but truck space 1.
                units_loaded += space_remaining_boxes*i;
                return units_loaded;
            } else {
                units_loaded += buckets[i]*i; // i is 10units/box. buckets[i] is 2 boxes. total units is 20.
                space_remaining_boxes -= buckets[i]; // space_remaining is in units of boxes.
            }
            
        }
        return units_loaded;
    }
};