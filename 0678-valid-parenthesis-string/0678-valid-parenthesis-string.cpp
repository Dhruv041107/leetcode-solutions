class Solution {
public:
    bool checkValidString(string s) {
        int lo=0,hi=0;

        for(auto & i:s){
            if(i=='('){
                lo++;
                hi++;
            }
            else if(i==')'){
                lo=max(lo-1,0);
                hi--;
            }
            else{
                lo=max(lo-1,0);
                hi++;
            }
            if(hi<0)    return false;
        }
        return lo==0;
    }
};