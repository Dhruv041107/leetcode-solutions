class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // int n=nums.size();
        // sort(nums.begin(),nums.end());
        // int cnt=0;
        // int longest=1;
        // int lastSmaller=INT_MAX;

        // for(int i=0;i<n;i++){
        //     if(nums[i]-1==lastSmaller){
        //         cnt+=1;
        //         lastSmaller=nums[i];
        //     }
        //     else if(nums[i]!=lastSmaller){
        //         cnt=1;
        //         lastSmaller=nums[i];
        //     }
        //     longest=max(longest,cnt);
        // }
        // return longest;


        int n=nums.size();
        if(n==0)    return 0;
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        int longest=1;
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int x=it;
                int cnt=1;
                while(st.find(x+1)!=st.end()){
                    cnt+=1;
                    x=x+1;
                }
                longest=max(longest,cnt);
            }
        }
        return longest;
    }
};