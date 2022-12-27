class Solution {
public:
    vector<double> convertTemperature(double cel) {
        vector<double> v(2,0);
        v[0] = cel + 273.15;
        v[1] = cel * 1.80 + 32.00;

        return v;
    }
};