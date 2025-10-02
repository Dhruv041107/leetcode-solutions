class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>freq;
        for(auto ch:s)   freq[ch]++;
        priority_queue<pair<int,char>>pq;
        for(auto &[ch,frq]:freq){
            pq.push({frq,ch});    
        }
        string ans="";
        while(!pq.empty()){
            auto [count,ch]=pq.top();
            pq.pop();
            ans.append(count,ch);
        }
        return ans;
    }
};