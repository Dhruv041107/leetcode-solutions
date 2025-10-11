class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freqMap;

        for(auto num:nums){
            freqMap[num]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(auto entry:freqMap){
            pq.push({entry.second,entry.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int>ans;
        while(!pq.empty()){
            auto [freq,num]=pq.top();
            pq.pop();
            ans.push_back(num);

        }
        return ans;
    }

};