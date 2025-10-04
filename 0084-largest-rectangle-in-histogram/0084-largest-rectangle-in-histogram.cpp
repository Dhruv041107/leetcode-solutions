class Solution {
public:
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
        int area=INT_MIN;

        for(int i=0;i<nextAns.size();i++){
            int width=nextAns[i]-prevAns[i]-1;
            int height=heights[i];
            int currAns=width*height;
            area=max(area,currAns);
        }

        return area;



    }
};