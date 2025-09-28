// class Solution {
// public:
//     int largestPerimeter(vector<int>& nums) {
//         int maxSum=0;
//         int n=nums.size();
//         sort(nums.begin(),nums.end());
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 for(int k=j+1;k<n;k++){
//                     if(nums[i]+nums[j]>nums[k]){
//                         int sum=nums[i]+nums[j]+nums[k];
//                         maxSum=max(sum,maxSum);
//                     }
//                 }
//             }
//         }
//         return maxSum;
//     }
// };
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i = n - 1; i >= 2; i--) {
            if(nums[i-2] + nums[i-1] > nums[i]) {
                return nums[i-2] + nums[i-1] + nums[i];
            }
        }
        return 0;
    }
};
