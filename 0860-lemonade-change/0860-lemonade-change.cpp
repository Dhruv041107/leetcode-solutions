class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0;

        for(auto &i:bills){
            if(i==5)    five++;
            else if(i==10){
                if(five<1)  return false;
                five--;
                ten++;
            }
            else if(i==20){
                if(five>0 &&  ten>0){
                    ten--;
                    five--;
                }
                else if(five>=3){
                    five-=3;
                }else{
                    return false;
                }

            }
        }
        return true;
    }
};