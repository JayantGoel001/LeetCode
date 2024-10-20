class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        // Traverse through the expression
        for (char currChar : expression) {
            if (currChar == ',' || currChar == '(')
                continue;  // Skip commas and open parentheses

            // Push operators and boolean values to the stack
            if (currChar == 't' || currChar == 'f' || currChar == '!' ||
                currChar == '&' || currChar == '|') {
                st.push(currChar);
            }
            // Handle closing parentheses and evaluate the subexpression
            else if (currChar == ')') {
                bool hasTrue = false, hasFalse = false;

                // Process the values inside the parentheses
                while (st.top() != '!' && st.top() != '&' && st.top() != '|') {
                    char topValue = st.top();
                    st.pop();
                    if (topValue == 't') hasTrue = true;
                    if (topValue == 'f') hasFalse = true;
                }

                // Pop the operator and evaluate the subexpression
                char op = st.top();
                st.pop();
                if (op == '!') {
                    st.push(hasTrue ? 'f' : 't');
                } else if (op == '&') {
                    st.push(hasFalse ? 'f' : 't');
                } else {
                    st.push(hasTrue ? 't' : 'f');
                }
            }
        }

        // The final result is at the top of the stack
        return st.top() == 't';
    }
};