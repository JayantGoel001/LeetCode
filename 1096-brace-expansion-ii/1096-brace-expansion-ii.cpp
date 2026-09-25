class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        vector<char> op;
        vector<set<string>> stk;

        // Pop the operator at the top of the stack and perform the calculation
        auto ope = [&]() {
            int l = stk.size() - 2, r = stk.size() - 1;
            if (op.back() == '+') {
                stk[l].merge(stk[r]);
            } else {
                set<string> tmp;
                for (auto& left : stk[l]) {
                    for (auto& right : stk[r]) {
                        tmp.insert(left + right);
                    }
                }
                stk[l] = move(tmp);
            }
            op.pop_back();
            stk.pop_back();
        };

        for (int i = 0; i < expression.size(); i++) {
            if (expression[i] == ',') {
                // Keep popping operators from the top of the stack until the
                // stack is empty or its top is not a multiplication sign
                while (op.size() && op.back() == '*') {
                    ope();
                }
                op.push_back('+');
            } else if (expression[i] == '{') {
                // First determine whether a multiplication sign needs to be
                // added, then push { onto the operator stack
                if (i > 0 &&
                    (expression[i - 1] == '}' || isalpha(expression[i - 1]))) {
                    op.push_back('*');
                }
                op.push_back('{');
            } else if (expression[i] == '}') {
                // Keep popping operators from the top of the stack until its
                // top is {
                while (op.size() && op.back() != '{') {
                    ope();
                }
                op.pop_back();
            } else {
                // First determine whether a multiplication sign needs to be
                // added, then push the newly constructed set onto the set stack
                if (i > 0 &&
                    (expression[i - 1] == '}' || isalpha(expression[i - 1]))) {
                    op.push_back('*');
                }
                stk.push_back({string(1, expression[i])});
            }
        }

        while (op.size()) {
            ope();
        }
        return {stk.back().begin(), stk.back().end()};
    }
};