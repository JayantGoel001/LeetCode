class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int cap = 0;
        int steps = 0;
        int size = plants.size();
        
        for(int i=0;i<size;i++){
            if(cap + plants[i] > capacity){
                cap = 0;
                steps += 2 * i;
            }
            cap += plants[i];
            steps++;
        }
        return steps;
    }
};