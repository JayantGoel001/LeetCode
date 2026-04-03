class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance,
                 vector<int>& walls) {
        int n = robots.size();
        vector<pair<int, int>> robotDist;
        for (int i = 0; i < n; i++) {
            robotDist.push_back({robots[i], distance[i]});
        }
        sort(robotDist.begin(), robotDist.end());
        sort(walls.begin(), walls.end());

        int m = walls.size();
        int rightPtr = 0, leftPtr = 0, curPtr = 0, robotPtr = 0;

        // DP variable: saves only the previous value
        int prevLeft = 0, prevRight = 0, prevNum = 0;
        int subLeft = 0, subRight = 0;

        for (int i = 0; i < n; i++) {
            int robotPos = robotDist[i].first;
            int robotDistVal = robotDist[i].second;

            // rightPtr finds the first position greater than robotPos
            // (corresponding to upper_bound)
            while (rightPtr < m && walls[rightPtr] <= robotPos) {
                rightPtr++;
            }
            int pos1 = rightPtr;

            // curPtr finds the first position >= robotPos (corresponding to
            // lower_bound)
            while (curPtr < m && walls[curPtr] < robotPos) {
                curPtr++;
            }
            int pos2 = curPtr;

            // leftPtr finds the first wall >= the left boundary
            int leftBound = (i >= 1) ? max(robotPos - robotDistVal,
                                           robotDist[i - 1].first + 1)
                                     : robotPos - robotDistVal;
            while (leftPtr < m && walls[leftPtr] < leftBound) {
                leftPtr++;
            }
            int leftPos = leftPtr;
            int currentLeft = pos1 - leftPos;

            // Count the number of walls that can be reached on the right side
            int rightBound = (i < n - 1) ? min(robotPos + robotDistVal,
                                               robotDist[i + 1].first - 1)
                                         : robotPos + robotDistVal;
            while (rightPtr < m && walls[rightPtr] <= rightBound) {
                rightPtr++;
            }
            int rightPos = rightPtr;
            int currentRight = rightPos - pos2;

            // robotPtr finds the position of the previous robot
            int currentNum = 0;
            if (i > 0) {
                while (robotPtr < m &&
                       walls[robotPtr] < robotDist[i - 1].first) {
                    robotPtr++;
                }
                int pos3 = robotPtr;
                currentNum = pos1 - pos3;
            }

            if (i == 0) {
                subLeft = currentLeft;
                subRight = currentRight;
            } else {
                int newsubLeft =
                    max(subLeft + currentLeft,
                        subRight - prevRight +
                            min(currentLeft + prevRight, currentNum));
                int newsubRight =
                    max(subLeft + currentRight, subRight + currentRight);
                subLeft = newsubLeft;
                subRight = newsubRight;
            }

            prevLeft = currentLeft;
            prevRight = currentRight;
            prevNum = currentNum;
        }

        return max(subLeft, subRight);
    }
};