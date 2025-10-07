class Solution {
public:
    vector<int> nextsmaller(vector<int>v){
        stack<int>st;
        st.push(-1);
        vector<int> ans(v.size(),-1);

        for(int i=v.size()-1;i>=0;i--){
            while(!st.empty() && st.top()!=-1 && v[st.top()]>v[i])    st.pop();

            ans[i]=st.top();
            st.push(i);
        }
        return ans;

    }
    vector<int> prevsmaller(vector<int>v){
        stack<int>st;
        st.push(-1);
        vector<int> ans(v.size(),-1);

        for(int i=0;i<v.size();i++){
            while(!st.empty() && st.top()!=-1 && v[st.top()]>=v[i])    st.pop();

            ans[i]=st.top();
            st.push(i);
        }
        return ans;

    }
    vector<int> nextGreater(vector<int>v){
        stack<int>st;
        st.push(-1);
        vector<int> ans(v.size(),-1);

        for(int i=v.size()-1;i>=0;i--){
            while(!st.empty() && st.top()!=-1 && v[st.top()]<v[i])    st.pop();

            ans[i]=st.top();
            st.push(i);
        }
        return ans;

    }
    vector<int> prevGreater(vector<int>v){
        stack<int>st;
        st.push(-1);
        vector<int> ans(v.size(),-1);

        for(int i=0;i<v.size();i++){
            while(!st.empty() && st.top()!=-1 && v[st.top()]<=v[i])    st.pop();

            ans[i]=st.top();
            st.push(i);
        }
        return ans;

    }
    long long sumSubarrayMins(vector<int>& arr) {
        auto next=nextsmaller(arr);
        auto prev=prevsmaller(arr);

        long long sum=0; 
        // const int mod=1e9+7;


        for(int i=0;i<arr.size();i++){
            long long nexti=next[i] ==-1 ? arr.size() :next[i];
            long long previ=prev[i];
            long long left=i-previ;
            long long right=nexti-i;
            // long long no_of_times=(left%mod * right%mod)%mod;
            // long long total=(no_of_times *arr[i])%mod;
            // sum=(sum + total)%mod;
            sum+=left*right*arr[i];
        }

        return sum;

    }
    long long sumSubarrayMax(vector<int>& arr) {
        auto next=nextGreater(arr);
        auto prev=prevGreater(arr);

        long long sum=0; 
        // const int mod=1e9+7;


        for(int i=0;i<arr.size();i++){
            long long nexti=next[i] ==-1 ? arr.size() :next[i];
            long long previ=prev[i];
            long long left=i-previ;
            long long right=nexti-i;
            // long long no_of_times=(left%mod * right%mod)%mod;
            // long long total=(no_of_times *arr[i])%mod;
            // sum=(sum + total)%mod;
            sum+=left*right*arr[i];
        }

        return sum;

    }
    long long subArrayRanges(vector<int>& nums) {
        auto sumofmaximus=sumSubarrayMax(nums); 
        auto sumofminimus=sumSubarrayMins(nums); 
        return sumofmaximus-sumofminimus;
    }
};