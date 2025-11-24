class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int oldremainder=0;
        vector<bool>ans;
        for(int i=0;i<nums.size();i++){
            int currentBit=nums[i];
            int newRemainder=(oldremainder*2+currentBit)%5;
            if(newRemainder)    ans.push_back(false);
            else    ans.push_back(true);
            oldremainder=newRemainder;
        }
        return ans;
    }
};