class Solution {
public:
    bool solve(vector<int>& weights,int mid, int days){
        int count=1;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
            if(sum>mid){
                count++;
                sum=weights[i];
            }
        }
        return count<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left=*max_element(weights.begin(),weights.end());
        int right =accumulate(weights.begin(),weights.end(),0);
        int ans =-1;
        while(left<=right){
            int mid=left+(right-left)/2;

            if(solve(weights,mid,days)){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};