class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        long xr =0 ;
        for(auto i:nums)    xr^=i;
        xr=(xr&xr-1)^xr;
        int b1=0,b2=0;
        for(auto i:nums){
            if(i&xr)   b1^=i;
            else    b2^=i;
        }
        return {b1,b2};
    }
};