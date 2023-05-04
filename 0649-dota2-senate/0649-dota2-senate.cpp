class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> qR, qS;
        
        for(int i = 0;i< senate.size();i++){
            if(senate[i] == 'R'){
                qR.push(i);
            }else{
                qS.push(i);
            }
        }
        while(!qR.empty() && !qS.empty()){
            int r = qR.front();
            qR.pop();
            
            int s = qS.front();
            qS.pop();
            
            if(r < s){
                qR.push(r + senate.size());
            }else{
                qS.push(s + senate.size());
            }
        }
        return qR.empty() ? "Dire" : "Radiant";
    }
};