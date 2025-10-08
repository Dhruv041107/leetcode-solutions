class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        int l=0,r=0,maxLen=0;

        while(r<fruits.size()){
            mp[fruits[r]]++;
            if(mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0)  mp.erase(fruits[l]);
                l++;
            }
            if(mp.size()<=2)    maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};