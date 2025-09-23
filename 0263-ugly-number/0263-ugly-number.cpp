class Solution {
public:
    bool isprime(int n){
        for(int i=2;i<n;i++){
            if(n%i==0)  return false;
        }
        return true;
    }
    bool isUgly(int n) {
        // if(n==1)    return true;
        // if(n<1) return false;

        // for(int i=2;i<n;i++){
        //     if(n%i==0){
        //         if(isprime(i)){
        //             if(i!=2 &&  i!=3 &&  i!=5){
        //                 return false;
        //             } 
        //         }
        //     }
        // }
        // return true;
        if (n <= 0) return false;
        int factors[3] = {2, 3, 5};

        for (int f : factors) {
            while (n % f == 0) {
                n /= f;
            }
        }

        return n == 1;

    }
};