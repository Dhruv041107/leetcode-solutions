class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // vector<int>ans;
        // int m=spells.size();
        // int n=potions.size();
        // for(int i=0;i<m;i++){
        //     int count=0;
        //     for(int j=0;j<n;j++){
        //         long long int product=1LL*spells[i]*potions[j];
        //         if(product>=success){
        //             count++;
        //         }
        //     }
        //     ans.push_back(count);
        // }
        // return ans;

        vector<int>ans;
        sort(potions.begin(),potions.end());
        int n=potions.size();

        for(int spell:spells){
            long long num=(success+spell-1)/spell;
            int idx=lower_bound(potions.begin(),potions.end(),num)-potions.begin();
            ans.push_back(n-idx);
        }
        return ans;
    }
};