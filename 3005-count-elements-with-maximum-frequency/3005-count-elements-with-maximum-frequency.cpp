class Solution {
public:
    // int maxFrequencyElements(vector<int>& nums) {
    //     unordered_map<int,int>mp;
    //     int count=0;
    //     int element=0;
    //     for(int i=0;i<nums.size();i++){
    //         mp[nums[i]]++;
    //         if(count==0){
    //             element=nums[i];
    //         }
    //         count+=element==nums[i]?1:-1;
    //     }
    //     int ans=0;
    //     if(mp.find(element)!=mp.end()){
    //         ans=mp[element];
    //     }
    //     int result=0;
    //     for(auto i:mp){
    //         if(ans==i.second){
    //             result+=i.second;
    //         }
    //     }
    //     return result;
    // }
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freq;
        int maxFreq = 0;

        for (int x : nums) {
            maxFreq = max(maxFreq, ++freq[x]);
        }

        int result = 0;
        for (auto &[num, f] : freq) {
            if (f == maxFreq) {
                result += f;
            }
        }

        return result;
    }
};