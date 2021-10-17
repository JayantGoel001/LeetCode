class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string ar[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        set<string> s;
        for(auto it : words){
            string str = "";
            for(auto s : it){
                str.append(ar[s - 'a']);
            }
            s.insert(str);
        }
        return s.size();
    }
};