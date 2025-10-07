class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;


        for(int i=0;i<k;i++){
            int element=nums[i];

            while(!dq.empty() && nums[dq.back()]<element)  dq.pop_back();


            dq.push_back(i);
        }


        int element=dq.front();
        int value=nums[element];
        ans.push_back(value);


        for(int i=k;i<nums.size();i++){
            if(!dq.empty() && dq.front()< i-k+1){
                dq.pop_front();
            }
            int element=nums[i];

            while(!dq.empty() && nums[dq.back()]<element)  dq.pop_back();


            dq.push_back(i);

            int index=dq.front();
            int value=nums[index];
            ans.push_back(value);


        }
        return ans;
    }
};