class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // vector<vector<int>>ans;
        // set<vector<int>>s;
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         for(int k=j+1;k<nums.size();k++){
        //             if(nums[i]+nums[j]+nums[k]==0){
        //                 vector<int>temp;
        //                 temp.push_back(nums[i]);
        //                 temp.push_back(nums[j]);
        //                 temp.push_back(nums[k]);
        //                 sort(temp.begin(),temp.end());
        //                 s.insert(temp);
        //             }
        //         }
        //     }
        // }
        // for(auto e:s){
        //     ans.push_back(e);
        // }





        //Method 2 
        // set<vector<int>>s;
        // for(int i=0;i<nums.size();i++){
        //     set<int>hashSet;
        //     for(int j=i+1;j<nums.size();j++){
        //         int third=-(nums[i]+nums[j]);
        //         if(hashSet.find(third)!=hashSet.end()){
        //             vector<int>temp={nums[i],nums[j],third};
        //             sort(temp.begin(),temp.end());
        //             s.insert(temp);
        //         }
        //         hashSet.insert(nums[j]);
        //     }
        // }
        // vector<vector<int>>ans;
        // for(auto e:s){
        //     ans.push_back(e);
        // }


        // Method 3 

        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])   continue;
            int j=i+1;
            int k=n-1;

            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0)   j++;
                else if(sum>0)  k--;
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1])    j++;
                    while(j<k && nums[k]==nums[k+1])    k--;
                }
            }
        }
        return ans;
    }
};