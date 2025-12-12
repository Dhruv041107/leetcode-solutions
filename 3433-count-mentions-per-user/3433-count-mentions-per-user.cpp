class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        int n = numberOfUsers, m = events.size();
        vector<int> order(m), ans(n,0), off(n,0);
        vector<char> on(n,1);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b){
            int ta = stoi(events[a][1]), tb = stoi(events[b][1]);
            if (ta != tb) return ta < tb;
            return events[a][0] == "OFFLINE" && events[b][0] == "MESSAGE";
        });

        for (int id : order) {
            int t = stoi(events[id][1]);
            for (int i = 0; i < n; i++) if (!on[i] && t >= off[i]) on[i] = 1;

            if (events[id][0] == "OFFLINE") {
                int u = stoi(events[id][2]);
                on[u] = 0;
                off[u] = t + 60;
            } else {
                string &msg = events[id][2];
                if (msg == "ALL") {
                    for (int i = 0; i < n; i++) ans[i]++;
                } else if (msg == "HERE") {
                    for (int i = 0; i < n; i++) if (on[i]) ans[i]++;
                } else {
                    string tok; stringstream ss(msg);
                    while (ss >> tok) ans[stoi(tok.substr(2))]++;
                }
            }
        }
        return ans;
    }
};