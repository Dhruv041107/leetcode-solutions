class Solution {
public:
    void solve(string &output,string digits,vector<string> &ans,unordered_map<char,string> &mapping,int i){
        if(i>=digits.length()){
            if(output.length()>0)   ans.push_back(output);
            return;
        }

        char digit=digits[i];
        string mappedstring=mapping[digit];
        for(char ch:mappedstring){
            output.push_back(ch);
            solve(output,digits,ans,mapping,i+1);
            output.pop_back();
        }
    }


    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        unordered_map<char,string> mapping;
        mapping['2']="abc";
        mapping['3']="def";
        mapping['4']="ghi";
        mapping['5']="jkl";
        mapping['6']="mno";
        mapping['7']="pqrs";
        mapping['8']="tuv";
        mapping['9']="wxyz";

        int i=0;
        string output="";

        solve(output,digits,ans,mapping,i);


        return ans;
    }
};