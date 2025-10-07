class Solution {
public:
    string multiply(string num1, string num2) {
        int m=num1.size();
        int n=num2.size();

        vector<int>result(n+m,0);
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int digit=(num1[i]-'0')*(num2[j]-'0');
                int sum=digit+result[i+j+1];
                result[i+j+1]=sum%10;
                result[i+j] +=sum/10;
            }
        }
        string ans="";

        for(int num:result){
            if(!(ans.empty() && num==0))    ans.push_back(num+'0');
        }
        return ans.empty()?"0":ans;
    }
};