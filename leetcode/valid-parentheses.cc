//  Valid Parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char &ch : s) {
            if (ch=='(' || ch=='[' || ch=='{')
                st.push(ch);
            if (ch == ')') {
                if (st.empty() || st.top()!='(')
                    return false;
                else    st.pop();
            }
            if (ch == ']') {
                if (st.empty() || st.top()!='[')
                    return false;
                else    st.pop();
            }
            if (ch == '}') {
                if (st.empty() || st.top()!='{')
                    return false;
                else    st.pop();
            }
        }
        return st.empty();
    }
};