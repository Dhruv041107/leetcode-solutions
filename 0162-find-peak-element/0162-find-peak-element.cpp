class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s=0;
        int n=nums.size();
        int e=n-1;
        int ans=0;
        while(s<=e){
            int mid=s+(e-s)/2;
            int currentvalue=nums[mid];
            long int right=INT_MIN;
            if(mid+1<n){
                right=nums[mid+1];
            }
            if(currentvalue> right){
                ans=mid;
                e=mid-1;
            }
            else
                s=mid+1;
        }
        return ans;
    }
};