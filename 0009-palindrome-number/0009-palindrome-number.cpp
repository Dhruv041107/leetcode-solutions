class Solution {
public:
    bool isPalindrome(int x) {
        string s=to_string(x);
        if(s[0]=='-')   return false;

        int i=0,j=s.length()-1;
        while(i<j){
            if(s[i]==s[j]){
                i++,j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};