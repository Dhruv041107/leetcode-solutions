class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>ans(nums.size(),-1);
        stack<int>st;
        
        int n=nums.size();

        for(int i=2*n-1;i>=0;i--){
            int idx=i%n;
            while(!st.empty() && st.top()<=nums[idx])   st.pop();

            if(i<n){
                if(st.empty())  ans[i]=-1;
                else    ans[i]=st.top();
            }
            st.push(nums[idx]);
        }
        return ans;
    }
};