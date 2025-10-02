class Solution {
public:
    int beautySum(string s) {
        int sum=0;
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp.clear();
            for(int j=i;j<s.size();j++){
                char &ch=s[j];
                mp[ch]++;


                int maxi=INT_MIN;
                int mini=INT_MAX;

                for(auto it:mp){
                    mini=min(mini,it.second);
                    maxi=max(maxi,it.second);
                }
                int sum1=maxi-mini;
                sum+=sum1;
            }
        }
        return sum;
    }

};