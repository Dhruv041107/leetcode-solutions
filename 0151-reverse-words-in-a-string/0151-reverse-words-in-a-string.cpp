class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int n=s.size();
        int start=0,end=0;
        for(int i=0;i<n;i++){
            while(i<n && s[i]==' ')
                i++;
            if(i==n)    break;
            while(i<n && s[i]!=' ')
                s[end++]=s[i++];
            reverse(s.begin()+start,s.begin()+end);
            s[end++]=' ';
            start=end;
        }
        s.resize(end-1);
        return s;

    }
};