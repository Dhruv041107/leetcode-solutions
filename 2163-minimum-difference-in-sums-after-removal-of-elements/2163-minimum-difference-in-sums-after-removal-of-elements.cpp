class Solution {
public:
#define ll long long
    long long minimumDifference(vector<int>& nums) {
        int n=nums.size();
        int k=n/3;
        vector<ll>prefix(n,-1),suffix(n,-1);

        ll sum=0;
        priority_queue<ll>pq;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            pq.push(nums[i]);

            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            if(pq.size()==k){
                prefix[i]=sum;
            }
        }
        sum=0;
        priority_queue<ll,vector<ll>,greater<ll>>pq2;
        for(int i=n-1;i>=0;i--){
            sum+=nums[i];
            pq2.push(nums[i]);

            if(pq2.size()>k){
                sum-=pq2.top();
                pq2.pop();
            }
            if(pq2.size()==k){
                suffix[i]=sum;
            }
        }
        ll ans=LONG_MAX;
        for(ll i=k-1;i<2*k;i++){
            ans=min(ans,prefix[i]-suffix[i+1]);
        }
        return ans;

    }
};