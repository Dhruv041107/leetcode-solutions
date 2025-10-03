class Solution {
public:
    int bSearch(int target_idx,vector<int>&nums,vector<long>&prefSum,int k){
        long long target=nums[target_idx];
        long long left=0;
        long long right=target_idx;
        long long best_idx=target_idx;

        while(left<=right){
            long long mid=left+(right-left)/2;
            long long count=target_idx-mid+1;
            long long maxSum=count*target;
            long long sumfromStart = prefSum[target_idx] - (mid > 0 ? prefSum[mid - 1] : 0);

            long long ops=maxSum-sumfromStart;
            if(ops>k)   left=mid+1;
            else{
                best_idx=mid;
                right=mid-1;
            }
        }
        return target_idx-best_idx+1;
    }
    int maxFrequency(vector<int>& nums, int k) {
        // sort(nums.begin(),nums.end());
        // int maxcnt=1;
        // for(int i=0;i<nums.size();i++){
        //     int cnt=1;
        //     int tempk=k;
        //     int j=i-1;
            
        //     while(j>=0){
        //         int diff=nums[i]-nums[j];
        //         if(diff<=tempk){
        //             tempk-=diff;
        //             cnt++;
        //             j--;
        //         }
        //         else    break;
        //     }
        //     maxcnt=max(maxcnt,cnt);
        // }
        // return maxcnt;

        int n=nums.size();
        sort(nums.begin(),nums.end());

        vector<long>prefSum(n);
        prefSum[0]=nums[0];
        for(int i=1;i<n;i++){
            prefSum[i]=nums[i]+prefSum[i-1];
        }

        int result=0;
        for(int i=0;i<n;i++){
            result=max(result, bSearch(i,nums,prefSum,k));
        }
        return result;
    }
};