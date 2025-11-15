class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();

        // prefix count of ones
        vector<int> cumCountOne(n, 0);
        cumCountOne[0] = s[0] == '1' ? 1 : 0;

        for(int i = 1; i < n; i++) {
            cumCountOne[i] = cumCountOne[i-1] + (s[i] == '1' ? 1 : 0);
        }

        int result = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {

                int oneCount = cumCountOne[j] - (i - 1 >= 0 ? cumCountOne[i-1] : 0);
                int zeroCount = (j - i + 1) - oneCount;
                if((zeroCount * zeroCount) > oneCount) {
                    int waste = (zeroCount * zeroCount) - oneCount;
                    j += waste - 1;
                }
                else if((zeroCount * zeroCount) == oneCount) {
                    result++;
                }
                else {
                    result++;

                    int k = sqrt(oneCount) - zeroCount;
                    int next = j + k;

                    if(next >= n) {
                        result += (n - j - 1);
                        break;
                    } else {
                        result += k;
                        j += k;
                    }
                }
            }
        }

        return result;
    }
};
