class Solution {
public:
    int divide(int dividendx, int divisorx) {
        if(dividendx == INT_MIN && divisorx == -1){
            return INT_MAX;
        }
        bool anssign=true;
        if(dividendx <0 && divisorx >0 || dividendx >0 && divisorx <0){
            anssign=false;
        }
        long long int dividend =abs(dividendx);
        long long int divisor =abs(divisorx);
        long long int s=0;
        long long int e=dividend;
        long long ans;
        while(s<=e){
            long long mid=s+((e-s)>>1);
            if(mid*divisor <= dividend ){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        if(anssign==false){
            return -ans;
        }
        return ans;
    }
};