#define ll long long int
class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        ll volume = (ll)length * (ll)width * (ll)height;
        
        bool bulky = volume >= 1e9 || length >= 1e4 || width >= 1e4 || height >= 1e4;
        bool heavy = mass >= 1e2;
        
        if(bulky && heavy){
            return "Both";
        }else if(bulky){
            return "Bulky";
        }else if(heavy){
            return "Heavy";
        }else{
            return "Neither";
        }
    }
};