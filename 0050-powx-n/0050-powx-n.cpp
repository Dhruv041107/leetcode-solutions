class Solution {
public:
    double myPow(double x,int n) {
        double ans=1.0;
        long nn=n;
        if(nn<0)    nn=nn*-1;
        while(nn>0){
            if(nn&1){
                ans=ans*x;
                nn=nn-1;
            }
            x=x*x;
            nn=nn>>1;
        }
        if(n<0) return (double)1.0/ans;
        return ans;
    }
};