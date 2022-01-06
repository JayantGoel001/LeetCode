class Solution {
	public:
		bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> car(1001, 0);
        for(auto trip: trips){
            car[trip[1]] += trip[0];
            car[trip[2]] -= trip[0];
        }
		int passengers = 0;
		for(auto p: car){
			passengers += p;
			if(passengers > capacity)
				return false;
		}
		return true;
	}
};