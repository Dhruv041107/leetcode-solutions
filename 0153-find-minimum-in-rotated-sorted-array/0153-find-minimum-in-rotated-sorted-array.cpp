class Solution {
public:

    int findMin(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int ans=nums[0];
        while(s<e){
            int mid=s+(e-s)/2;

            if(nums[mid]>nums[e]){
                s=mid+1;
            }
            else{
                // ans=nums[mid];
                e=mid;
            }
        }
        return nums[s];
    }
};