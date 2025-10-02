class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int balance=0;

        for(auto ch:s){
            if(ch=='('){
                if(balance) ans+="(";
                balance++;
            }
            else{
                balance--;
                if(balance) ans+=")"; 
            }
        }
        return ans;
    }
};