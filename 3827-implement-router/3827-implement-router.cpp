class Router {
private:
    int size;
    unordered_map<long long, vector<int>> packets;
    unordered_map<int, vector<int>> counts;
    queue<long long> q;

    long long encode(int source, int destination, int timestamp) {
        return ((long long)source << 40) | ((long long)destination << 20) | timestamp;
    }

    int lowerBound(vector<int>& list, int target) {
        return (int)(lower_bound(list.begin(), list.end(), target) - list.begin());
    }

    int upperBound(vector<int>& list, int target) {
        return (int)(upper_bound(list.begin(), list.end(), target) - list.begin());
    }

public:
    Router(int memoryLimit) {
        size = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        long long key = encode(source, destination, timestamp);

        if (packets.find(key) != packets.end())
            return false;

        if ((int)packets.size() >= size)
            forwardPacket();

        packets[key] = {source, destination, timestamp};
        q.push(key);
        counts[destination].push_back(timestamp);

        return true;
    }

    vector<int> forwardPacket() {
        if (packets.empty()) return {};

        long long key = q.front();
        q.pop();

        vector<int> packet = packets[key];
        packets.erase(key);

        int dest = packet[1];
        counts[dest].erase(counts[dest].begin());  // remove earliest timestamp

        return packet;
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = counts.find(destination);
        if (it == counts.end() || it->second.empty())
            return 0;

        vector<int>& list = it->second;

        int left = lowerBound(list, startTime);
        int right = upperBound(list, endTime);

        return right - left;
    }
};