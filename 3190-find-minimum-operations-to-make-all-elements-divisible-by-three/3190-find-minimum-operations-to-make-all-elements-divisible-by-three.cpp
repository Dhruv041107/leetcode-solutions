class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count=0;

        for(auto i:nums){
            count+= i%3==0?0:1;
        }
        return count;
    }
};