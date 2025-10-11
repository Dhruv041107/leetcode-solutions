class Solution {
public:
    int atmost(vector<int>&nums,int k){
        unordered_map<int,int>mp;

        int l=0,r=0,result=0;

        while(r<nums.size()){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0)  mp.erase(nums[l]);
                l++;
            }
            result+=r-l+1;
            r++;
        }
        return result;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};