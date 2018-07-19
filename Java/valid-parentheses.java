//  Valid Parentheses

// Time O(N), Space O(N)
class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<Character>();
        for (int i=0; i<s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == '(')
                st.push(ch);
            if (ch == '[')
                st.push(ch);
            if (ch == '{')
                st.push(ch);
            if (ch == ')') {
                if (st.empty() || st.peek()!='(')
                    return false;
                else
                    st.pop();
            }
            if (ch == ']') {
                if (st.empty() || st.peek()!='[')
                    return false;
                else
                    st.pop();
            }
            if (ch == '}') {
                if (st.empty() || st.peek()!='{')
                    return false;
                else
                    st.pop();
            }
        }
        return st.empty();
    }
}