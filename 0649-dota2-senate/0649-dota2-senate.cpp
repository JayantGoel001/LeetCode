class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> qR, qD;

        for(int i=0;i<senate.size();i++) {
            if (senate[i] == 'R') qR.push(i);
            else qD.push(i);
        }

        int size = senate.size();
        while(!qD.empty() && !qR.empty()) {
            if (qD.front() < qR.front()) {
                qD.push(size++);
            } else {
                qR.push(size++);
            }
            qD.pop();
            qR.pop();
        }

        return qD.empty() ? "Radiant" : "Dire";
    }
};