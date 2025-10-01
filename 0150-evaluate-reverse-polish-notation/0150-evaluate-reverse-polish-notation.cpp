class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (auto &tok : tokens) {
            if (tok == "+" || tok == "-" || tok == "*" || tok == "/") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();

                if (tok == "+") st.push(b + a);
                else if (tok == "-") st.push(b - a);
                else if (tok == "*") st.push(b * a);
                else st.push(b / a); 
            } 
            else {
                st.push(stoi(tok));
            }
        }
        return st.top();
    }
};
