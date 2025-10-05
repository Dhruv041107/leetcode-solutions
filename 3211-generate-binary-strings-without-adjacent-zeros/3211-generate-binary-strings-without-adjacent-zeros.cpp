class Solution {
public:
    void generateString(int ones,int zeros,string current,vector<string>&ans){
        if(ones<0 || zeros<0)   return;
        if(ones==0 && zeros==0){
            ans.push_back(current);
            return;
        }
        if(current.empty() || current.back()== '1'){
            current.push_back('0');
            generateString(ones,zeros-1,current,ans);
            current.pop_back();
        }
        current.push_back('1');
        generateString(ones-1,zeros,current,ans);
        current.pop_back();
    }
    vector<string> validStrings(int n) {
        vector<string>ans;
        for( int numZeros=0;numZeros<=n;numZeros++){
            int numOnes=n-numZeros;
            string current="";
            generateString(numOnes,numZeros,current,ans);
        }
        return ans;
    }
};