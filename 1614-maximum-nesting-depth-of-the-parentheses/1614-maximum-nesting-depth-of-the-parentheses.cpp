class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int i=0,maxcnt=INT_MIN;

        while(i<s.length()){
            char ch=s[i];
            if(isdigit(s[i])){
                int size=st.size();
                maxcnt=max(maxcnt,size);
            }
            else if(ch=='(')    st.push(ch);
            else if(ch==')' && !st.empty()){
                int size=st.size();
                maxcnt=max(maxcnt,size);
                st.pop();
            }
            i++;
        }   
        return maxcnt;
    }
};