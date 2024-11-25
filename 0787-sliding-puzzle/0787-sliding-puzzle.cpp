class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // Direction map for zero's possible moves in a 1D representation of the
        // 2x3 board
        vector<vector<int>> directions = {{1, 3}, {0, 2, 4}, {1, 5},
                                          {0, 4}, {1, 3, 5}, {2, 4}};

        string target = "123450";
        string startState;

        // Convert the 2D board into a string representation
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                startState += to_string(board[i][j]);
            }
        }

        unordered_set<string> visited;  // To store visited states
        queue<string> queue;
        queue.push(startState);
        visited.insert(startState);

        int moves = 0;

        // BFS to find the minimum number of moves
        while (!queue.empty()) {
            int size = queue.size();
            while (size-- > 0) {
                string currentState = queue.front();
                queue.pop();

                // Check if we reached the target solved state
                if (currentState == target) {
                    return moves;
                }

                int zeroPos = currentState.find('0');
                for (int newPos : directions[zeroPos]) {
                    string nextState = currentState;
                    swap(nextState[zeroPos], nextState[newPos]);

                    // Skip if this state has been visited
                    if (visited.count(nextState)) continue;

                    // Mark the new state as visited and add it to the queue
                    visited.insert(nextState);
                    queue.push(nextState);
                }
            }
            moves++;
        }
        return -1;
    }
};