class Solution {
public:
    int solve(vector<int>& nums, int mid) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += ceil(nums[i] / (double)mid);
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int temp = solve(nums, mid);

            if (temp <= threshold) {  
                ans = mid;     
                right = mid - 1; 
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
