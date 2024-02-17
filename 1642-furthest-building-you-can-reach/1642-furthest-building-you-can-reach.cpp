class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int hsum=0;
        int i=0;
        priority_queue<int>maxheap;
        
        while(i<heights.size()-1){
            if(heights[i]<heights[i+1]){
                hsum+=heights[i+1]-heights[i];
                maxheap.push(heights[i+1]-heights[i]);
                
                while(hsum>bricks && ladders>0){
                    hsum-=maxheap.top();
                    maxheap.pop();
                    ladders--;
                }
                if(hsum>bricks && ladders==0){
                    break;
                }
            }
            i++;
        }
        return i;    
    }
};