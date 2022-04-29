class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto token:tokens) {
            if(token == "+" || token == "-" || token == "*" || token == "/") {
                int s1 = st.top();
                st.pop();
                int s2 = st.top();
                st.pop();
                st.push(token=="+" ? s1+s2:token=="-"? s2-s1:token=="*"? s1*s2:s2/s1   );
                
            } else st.push(stoi(token));
        }
        return st.top();
    }
};