class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });

        int a = -1, b = -1;
        int ans = 0;

        for (auto &in : intervals) {
            int start = in[0], end = in[1];

            if (b < start) {
                ans += 2;
                a = end - 1;
                b = end;
            }
            else if (a < start) {
                ans += 1;
                a = b;
                b = end;
            }
        }

        return ans;
    }
};
