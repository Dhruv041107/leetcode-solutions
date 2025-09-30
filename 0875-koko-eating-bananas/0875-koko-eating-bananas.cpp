class Solution {
public:
    bool itcan(vector<int>&piles,int h,int k){
        long double takenhour = 0;
        for(int i=0;i<piles.size();i++){
            takenhour += ceil(piles[i]/ (double) k );
        }
        if(takenhour<=h){
            return true;
        }
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start=0;
        auto it=max_element(piles.begin(),piles.end());
        int end=*it;
        int ans=-1;
        while(start<= end){
            int mid=start+(end-start)/2;
            int k=mid;
            if(itcan(piles,h,k)){
                ans=k;
                end=mid-1;
            }
            else
                start=mid+1;
        }
        return ans;
    }
};