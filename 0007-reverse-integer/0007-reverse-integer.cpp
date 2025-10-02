class Solution {
public:
    int reverse(int x) {
        int ans=0;
        int num=0;
        bool nega=false;
        if(x<=INT_MIN){
            return 0;
        }
        if(x<0){
            nega=true;
            x=-x;
        }
        while(x>0){
            if(ans>INT_MAX/10){
                return 0;
            }
            num=x%10;
            ans=ans*10+num;
            x/=10;
        }
        return nega?-ans :ans;
    }
};