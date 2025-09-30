class Solution {
public:
    int triangularSum(vector<int>& nums) {
        // int n = nums.size();
        // while (n > 1) {
        //     vector<int> temp(n - 1);
        //     for (int i = 0; i < n - 1; i++) {
        //         temp[i] = (nums[i] + nums[i + 1]) % 10;
        //     }
        //     nums =  move(temp);
        //     n--;
        // }
        // return nums[0];

        int n=nums.size();
        int i=0;
        while(n>1){
            for(int i=0;i<n-1;i++){
                nums[i]=(nums[i]+nums[i+1])%10;
            }
            n--;
        }
        return nums[0];
    }
};
