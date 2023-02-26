class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int z = 0;
        int o = 0;
        
        for(auto it : students){
            z += it == 0;
            o += it == 1;
        }
        int i = 0;
        while(i < sandwiches.size() && ((sandwiches[i] == 0 && z != 0) || (sandwiches[i] == 1 && o != 0))){
            z -= sandwiches[i] == 0;
            o -= sandwiches[i] == 1;
            i++;
        }
        return students.size() - i;
    }
};