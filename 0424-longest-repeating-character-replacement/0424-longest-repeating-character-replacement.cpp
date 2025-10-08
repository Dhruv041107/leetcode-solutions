class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,maxLen=0;
        vector<int>freq(26,0);
        int maxfreq=0;
        while(r<s.length()){
            freq[s[r]-'A']++;
            maxfreq=max(maxfreq,freq[s[r]-'A']);
            if(r-l+1 - maxfreq >k){
                freq[s[l]-'A']--;
                l++;
            }
            else{
                maxLen=max(maxLen,r-l+1);
            }
            r++;
        }
        return maxLen;
    }
};