class Solution {
public:
    int atmost(vector<int>&nums,int k){
        int l=0,res=0;
        for(int r=0;r<nums.size();r++){
            if(nums[r]&1)   k--;
            while(k<0){
                if(nums[l]&1)   k++;
                l++;
            }
            res+=(r-l+1);
        }
        return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};