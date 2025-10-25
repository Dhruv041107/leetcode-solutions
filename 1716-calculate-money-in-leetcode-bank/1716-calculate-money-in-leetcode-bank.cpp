class Solution {
public:
    int totalMoney(int n) {
        int terms=n/7;

        int first=28;
        int last=28+(terms-1)*7;

        int result=terms*(first+last)/2;

        int remain=n%7;
        int first_term=(1+terms);
        int last_term=first_term+remain-1;
        result+=remain*(first_term+last_term)/2;
        return result;
    }
};