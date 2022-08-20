class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        
        priority_queue<int> pq; //max heap
        /*
			if we can't reach target, I will first use the largestfuel Station
			(which can take me farthest) and move ahead and keep doing this.
        */
        int curr = startFuel; //my current position
        int i = 0; //station index
        int result = 0;
        while(curr < target) { //until I reach my target
            while(i < n && curr >= stations[i][0]) {
                /*
					  Sice, I am already ahead of or at this station
					  (i.e. curr >= stations[i][0])  we don't use this
					  station and try to move ahead but I store this
					  station in maxheap to use in future
				*/
                pq.push(stations[i][1]);
				//Keep the station at top which can take me farthest (maximum gas)
                i++;
            }
            
            if(pq.empty()) //we can't move further now
                return -1;
            
            int dist = pq.top();
            pq.pop();
            
            curr += dist;
            result++;
        }
        
        return result;
        
    }
};