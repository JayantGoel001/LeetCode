class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> folderStack;

        for (const string& currentOperation : logs) {
            if (currentOperation == "../") {
                // Move up to parent directory if not already at main folder
                if (!folderStack.empty()) {
                    folderStack.pop();
                }
            } else if (currentOperation != "./") {
                // Enter a new folder
                folderStack.push(currentOperation);
            }
            // Ignore "./" operations as they don't change the current folder
        }

        // The stack size represents the number of folders deep we are
        return folderStack.size();
    }
};