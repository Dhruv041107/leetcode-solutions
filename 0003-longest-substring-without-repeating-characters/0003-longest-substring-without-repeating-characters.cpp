class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char>lastIndex(26,-1);
        int ans=0;
        int start=0;
        for( int end=0;end<s.length();end++){
            int idx=s[end]-'a';
            if(lastIndex[idx]>=start){
                start=lastIndex[idx]+1;
            }
            lastIndex[idx]=end;
            ans=max(ans,end-start+1);
        }
        return ans;
    }
};