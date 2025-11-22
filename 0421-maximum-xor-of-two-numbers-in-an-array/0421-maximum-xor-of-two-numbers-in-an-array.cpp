class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0, mask = 0;
        
        for (int i = 31; i >= 0; i--) {
            mask |= (1 << i);
            unordered_set<int> s;
            for (int x : nums) s.insert(x & mask);
            
            int candidate = ans | (1 << i);
            
            for (int p : s) {
                if (s.count(p ^ candidate)) {
                    ans = candidate;
                    break;
                }
            }
        }
        return ans;
    }
};
