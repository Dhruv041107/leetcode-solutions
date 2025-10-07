class Solution {
    void nextsmallerelement(vector<int> arr,vector<int>&nextAns){
        stack<int>st;
        st.push(-1);

        int n =arr.size();

        for(int i=n-1;i>=0;i--){
            int element=arr[i];

            while(st.top()!=-1 && arr[st.top()]>=element){
                st.pop();
            }
            nextAns.push_back(st.top());

            st.push(i);
        }
    }
    void prevsmallerelement(vector<int> arr,vector<int>&prevAns){
        stack<int>st;
        st.push(-1);

        int n =arr.size();

        for(int i=0;i<n;i++){
            int element=arr[i];

            while(st.top()!=-1 && arr[st.top()]>=element){
                st.pop();
            }
            prevAns.push_back(st.top());

            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>nextAns;
        vector<int>prevAns;
        nextsmallerelement(heights,nextAns);
        reverse(nextAns.begin(),nextAns.end());
        for(int i=0;i<nextAns.size();i++){
            if(nextAns[i]==-1){
                nextAns[i]=nextAns.size();
            }
        }
        prevsmallerelement(heights,prevAns);
        int area=0;

        for(int i=0;i<nextAns.size();i++){
            int width=nextAns[i]-prevAns[i]-1;
            int height=heights[i];
            int currAns=width*height;
            area=max(area,currAns);
        }

        return area;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>>v;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            vector<int>t;
            for(int j=0;j<n;j++){
                t.push_back(matrix[i][j]-'0');
            }
            v.push_back(t);
        }
        int area=largestRectangleArea(v[0]);
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]){
                    v[i][j]+=v[i-1][j];
                }
                else{
                    v[i][j]=0;
                }
            }
            area=max(area,largestRectangleArea(v[i]));
        }
        return area;
    }
};