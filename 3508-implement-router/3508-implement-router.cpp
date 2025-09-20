class Router {
public:
    int MAX_SIZE;
    unordered_map<string, vector<int>> packetStore; // key -> {S, D, T}
    unordered_map<int, vector<int>> destTimeMap;    // D -> sorted timestamps
    queue<string> que;

    Router(int memoryLimit) {
        MAX_SIZE = memoryLimit;
    }

    string makeKey(int s, int d, int t) {
        return to_string(s) + "_" + to_string(d) + "_" + to_string(t);
    }

    bool addPacket(int source, int destination, int timestamp) {
        string key = makeKey(source, destination, timestamp);

        if (packetStore.find(key) != packetStore.end()) return false;

        if (que.size() >= MAX_SIZE) {
            forwardPacket();
        }

        packetStore[key] = {source, destination, timestamp};
        que.push(key);

        destTimeMap[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (packetStore.empty()) return {};

        string key = que.front();
        que.pop();

        vector<int> packet = packetStore[key];
        packetStore.erase(key);

        int D = packet[1], T = packet[2];

        auto &v = destTimeMap[D];

        auto it = lower_bound(v.begin(), v.end(), T);
        if (it != v.end() && *it == T) {
            v.erase(it);
        }

        return packet;
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = destTimeMap.find(destination);
        if (it == destTimeMap.end() || it->second.empty()) return 0;

        auto &timestamps = it->second;

        int i = lower_bound(timestamps.begin(), timestamps.end(), startTime) - timestamps.begin();
        int j = upper_bound(timestamps.begin(), timestamps.end(), endTime) - timestamps.begin();

        return j - i;
    }
};
