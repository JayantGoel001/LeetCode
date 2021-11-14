class CombinationIterator {
public:

	// Array of pointers
    vector<bool> bits; 
    int n;
	
	// Boolean tracking if the next permutation is possible
    bool possible = true;
    string str;
	
	// Length of the combination required
    int len;
    
    CombinationIterator(string s, int len) {
        str = s;
        this -> len = len;
        n = s.size();
        bits.resize(n, 0);
        
        // First Permutation
        for(int i = 0; i < len; i++) {
            bits[i] = 1;
        }
    }
    
    string next() {
        string ans = "";
        
        // Generating the current combination
        for(int i = 0; i < n; i++) {
            if(bits[i])
                ans += str[i];
        }
        
        // Permuting bits so that it points to the next combination
        
        // Case 1: Last bit is not set!
        if(bits[n - 1] == 0) {
            // Simply shift the rightmost free 1 ahead!
            for(int i = n - 1; i >= 0; i--) {
                if(bits[i]) {
                    bits[i + 1] = 1;
                    bits[i] = 0;
                    break;
                }
            }
        } else {
            
            // Count the number of 1s at the end and simultaneously 
            // setting them to 0
            int onesAtLast = 0;
            int i = n - 1;
            while(i >= 0 && bits[i]) {
                bits[i] = 0;
                onesAtLast++;
                i--;
            }
            
            // If all 1s are at the end, then we have already covered
            // the final combination, and no other combination
            // is possible!
            if(onesAtLast == len) {
                possible = false;
            } else {
                
                // Now finding the rightmost free 1
                while(i >= 0 && bits[i] == 0) {
                    i--;
                }
                
                // Shifting it ahead
                bits[i++] = 0;
                bits[i++] = 1;
                
                // Shifting onesAtLast number of 1s after the 
                // newly shifted 1
                while(onesAtLast--) {
                    bits[i++] = 1;
                }
            }
        }
        
        // Returning the computed string
        return ans;
    }
    
    bool hasNext() {
        return possible;
    }
};