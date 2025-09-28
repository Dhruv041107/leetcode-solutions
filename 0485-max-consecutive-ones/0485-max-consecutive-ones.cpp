class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int maxLen=INT_MIN;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=1){
                maxLen=max(maxLen,count);
                count=0;
            }
            else{
                count++;
            }
        }
        maxLen=max(maxLen,count);
        return maxLen;
    }
};