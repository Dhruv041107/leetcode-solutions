class Solution {
public:
    int countKeyChanges(string s) {
        char ch=s[0];
        int count=0;
        for(int i=1;i<s.length();i++){
            if(tolower(s[i])!=tolower(ch)){
                count++;
            }
            ch=s[i];

        }
        return count;
    }
};