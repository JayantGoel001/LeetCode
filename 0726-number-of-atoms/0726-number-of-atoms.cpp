class Solution {
public:
    string countOfAtoms(string formula) {
        // Every element of matcher will be a quintuple
        regex reg("([A-Z][a-z]*)(\\d*)|(\\()|(\\))(\\d*)");
        sregex_iterator it(formula.begin(), formula.end(), reg);
        sregex_iterator end;
        vector<tuple<string, string, string, string, string>> matcher;
        while (it != end) {
            matcher.push_back(
                {(*it)[1], (*it)[2], (*it)[3], (*it)[4], (*it)[5]});
            it++;
        }
        reverse(matcher.begin(), matcher.end());

        // Map to store the count of atoms
        unordered_map<string, int> finalMap;

        // Stack to keep track of the nested multiplicities
        stack<int> stack;
        stack.push(1);

        // Current Multiplicity
        int runningMul = 1;

        // Parse the formula
        for (auto& quintuple : matcher) {
            string atom = get<0>(quintuple);
            string count = get<1>(quintuple);
            string left = get<2>(quintuple);
            string right = get<3>(quintuple);
            string multiplier = get<4>(quintuple);

            // If atom, add it to the final map
            if (!atom.empty()) {
                int cnt = count.empty() ? 1 : stoi(count);
                finalMap[atom] += cnt * runningMul;
            }

            // If the right parenthesis, multiply the runningMul
            else if (!right.empty()) {
                int currMultiplier = multiplier.empty() ? 1 : stoi(multiplier);
                runningMul *= currMultiplier;
                stack.push(currMultiplier);
            }

            // If left parenthesis, divide the runningMul
            else if (!left.empty()) {
                runningMul /= stack.top();
                stack.pop();
            }
        }

        // Sort the final map
        map<string, int> sortedMap(finalMap.begin(), finalMap.end());

        // Generate the answer string
        string ans;
        for (auto& [atom, count] : sortedMap) {
            ans += atom;
            if (count > 1) {
                ans += to_string(count);
            }
        }

        return ans;
    }
};