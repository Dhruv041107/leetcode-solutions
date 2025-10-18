class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n=nums.size();
        sort(begin(nums),end(nums));

        int prev=INT_MIN;

        int count=0;
        for(int i=0;i<n;i++){
            int minValue=nums[i]-k;
            if(prev<minValue){
                prev=minValue;
                count++;
            }
            else if(prev<nums[i]+k){
                prev++;
                count++;
            }
        }
        return count;
    }
};