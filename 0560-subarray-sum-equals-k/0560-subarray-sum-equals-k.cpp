class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // int count=0;
        // for(int i=0;i<nums.size();i++){
        //     int sum=0;
        //     for(int j=i;j<nums.size();j++){
        //         sum+=nums[j];
        //         if(sum==k)  count++;
        //     }
        // }
        // return count;

        // int count=0;
        // int left=0,right=0;
        // long long sum=nums[0];
        // int n=nums.size();
        // while(right<n){
        //     while(left<=right && sum>k)
        //         sum-=nums[left++];
        //     if(sum==k)  count++;
        //     right++;
        //     if(right<n) sum+=nums[right];
        // }
        // return count;
        int n=nums.size();
        map<int,int>mp;
        int sum=0,count=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==k){
                count++;
            }
            int rem=sum-k;
            if(mp.find(rem)!=mp.end()){
                count++;
            }
            if(mp.find(sum)==mp.end())  mp[sum]=i;
        }
        return count;
    }
};