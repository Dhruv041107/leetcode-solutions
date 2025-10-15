class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        int prevCnt=0;
        int currCnt=1;
        int K=0;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                currCnt++;
            }
            else{
                prevCnt=currCnt;
                currCnt=1;
            }
            K=max(K,currCnt/2);
            K=max(K,min(currCnt,prevCnt));
        }
        return K;
    }
};