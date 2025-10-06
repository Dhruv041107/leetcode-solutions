class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int size=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<size){
            if(i+2<size &&nums[i]==nums[i+1] && nums[i]==nums[i+2]&& i+2<size){
                i+=3;
            }
            else
                return nums[i];
        }
        return -1;
    }
};