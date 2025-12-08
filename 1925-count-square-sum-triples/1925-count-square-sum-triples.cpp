class Solution {
public:
    int countTriples(int n) {
        long long ans = 0;
        for (int c = 1; c <= n; ++c) {
            long long c2 = 1LL * c * c;
            for (int a = 1; a < c; ++a) {
                long long a2 = 1LL * a * a;
                long long b2 = c2 - a2;
                if (b2 <= 0) continue;
                long long b = (long long) llround(sqrt((long double) b2));
                if (b * b == b2 && b >= 1 && b <= n) {
                    ans++;
                }
            }
        }
        return (int)ans;
    }
};