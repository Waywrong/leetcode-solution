//  Evaluate Reverse Polish Notation

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto &s : tokens) {
            int a, b;
            if (s == "+") {
                a = st.top(); st.pop();
                b = st.top(); st.pop();
                st.push(a+b);
            }
            else if (s == "-") {
                a = st.top(); st.pop();
                b = st.top(); st.pop();
                st.push(b-a);
            }
            else if (s == "*") {
                a = st.top(); st.pop();
                b = st.top(); st.pop();
                st.push(a * b);
            }
            else if (s == "/") {
                a = st.top(); st.pop();
                b = st.top(); st.pop();
                st.push(b / a);
            }
            else 
                st.push(atoi(s.c_str()));
        }
        return st.top();
    }
};
