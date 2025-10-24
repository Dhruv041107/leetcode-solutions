class Solution {
public:
    vector<int>digitCount={0,1,2,3,4,5,6,7,8,9};
    int backTrack(int n,int curr,int count){
        if(count==0){
            for(int digit=1;digit<=9;digit++){
                if(digitCount[digit]!=0 && digitCount[digit]!=digit){
                    return 0;
                }
            }
            return curr>n ?curr:0;
        }
        int result=0;

        for(int digit=1;digit<=9;digit++){
            if(digitCount[digit]!=0 && digitCount[digit]<=count){
                digitCount[digit]--;
                result=backTrack(n,curr*10+digit,count-1);
                digitCount[digit]++;
            }
            if(result!=0)   break;
        }
        return result;
    }
    int nextBeautifulNumber(int n) {
        int numDigit=to_string(n).length();

        int result= backTrack(n,0,numDigit);
        if(result==0)
            result=backTrack(n,0,numDigit+1);
        return result;
    }
};