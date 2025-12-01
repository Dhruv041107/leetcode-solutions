class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long total = 0;
        for (int b : batteries) total += b;
        long long lo = 0, hi = total / n;

        while (lo < hi) {
            long long mid = lo + (hi - lo + 1) / 2;
            long long contrib = 0;
            for (int b : batteries) {
                contrib += min<long long>(b, mid);
                if (contrib >= (long long)n * mid) break;
            }
            if (contrib >= (long long)n * mid) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        return lo;
    }
};
