class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(auto ast:asteroids){
            bool destroy=false;
            if(ast>0){
                st.push(ast);
            }
            else{
                if (st.empty() || st.top() < 0) {
                    st.push(ast);
                }
                else{
                    while(!st.empty() && st.top()>0){
                        if(abs(ast)==st.top()){
                            st.pop();
                            destroy=true;
                            break;
                        }
                        else if(abs(ast)>st.top()){
                            st.pop();
                        }
                        else{
                            destroy=true;
                            break;
                        }
                    }
                    if(!destroy){
                        st.push(ast);
                    }
                }
            }
        }
        if(st.size()==asteroids.size()) return asteroids;
        vector<int>ans(st.size());
        for(int i=ans.size()-1;i>=0;i--){
            ans[i]=st.top();
            st.pop();
        }
        return ans;
    }
};