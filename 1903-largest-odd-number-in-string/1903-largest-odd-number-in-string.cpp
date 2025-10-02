class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        if((num[n-1]-'0')&1)    return num;
        int i=n-1;
        while(i>=0){
            int ch=num[i]-'0';
            if(ch&1){
                string s=num.substr(0,i+1);
                return s;
            }
            i--;
        }
        return "";
    }
};