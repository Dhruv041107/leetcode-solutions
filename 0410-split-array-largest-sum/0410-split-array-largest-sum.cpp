class Solution {
public:
    int solve(vector<int>&nums,int mid){
        int count=1;
        int sumCount=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]+sumCount<=mid){
                sumCount+=nums[i];
            }
            else{
                count++;
                sumCount=nums[i];
            }
        }
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        int left=*max_element(nums.begin(),nums.end());
        int right=accumulate(nums.begin(),nums.end(),0);
        
        while(left<=right){
            int mid=left+(right-left)/2;

            int sum=solve(nums,mid);
            if(sum>k)   left=mid+1;
            else    right=mid-1;
        }
        return left;
    }
};