class Solution {
public:
    bool canAchieve(long long target, vector<long long>& power, int r, long long k) {
        int n = power.size();
        vector<long long> addDiff(n + 1, 0);
        long long runningAdd = 0;
        long long remainingK = k;

        for (int i = 0; i < n; ++i) {
            runningAdd += addDiff[i];
            long long currentPower = power[i] + runningAdd;

            if (currentPower < target) {
                long long need = target - currentPower;
                if (need > remainingK) return false;

                remainingK -= need;

                int pos = min(i + r, n - 1);
                int L = max(0, pos - r);
                int R = min(n - 1, pos + r);

                addDiff[L] += need;
                if (R + 1 < n) addDiff[R + 1] -= need;
                runningAdd += need;
            }
        }
        return true;
    }

    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();

        vector<long long> diff(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            int left = max(0, i - r);
            int right = min(n - 1, i + r);
            diff[left] += stations[i];
            if (right + 1 < n) diff[right + 1] -= stations[i];
        }

        vector<long long> power(n);
        long long cur = 0;
        for (int i = 0; i < n; ++i) {
            cur += diff[i];
            power[i] = cur;
        }

        long long lo = 0, hi = (1LL << 40);
        while (lo < hi) {
            long long mid = (lo + hi + 1) / 2;
            if (canAchieve(mid, power, r, k))
                lo = mid;
            else
                hi = mid - 1;
        }
        return lo;
    }
};
