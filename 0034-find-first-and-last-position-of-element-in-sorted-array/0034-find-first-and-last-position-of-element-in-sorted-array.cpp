class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int e=nums.size()-1;
        int s=0;
        vector<int> result(2,-1);
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                result[0]=mid;
                e=mid-1;
            }
            if(nums[mid]<target)    s=mid+1;
            else if (nums[mid]>target)    
                e=mid-1;
        }
        e=nums.size()-1;
        s=0;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                result[1]=mid;
                s=mid+1;
            }
            if(nums[mid]<target)    s=mid+1;
            else if (nums[mid]>target)      
                e=mid-1;
        }
        return result;
    }
};