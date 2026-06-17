#include <stack>
#include <string>
bool isValid(std::string s) {
    std::stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty())
                return false;
            switch (c) {
                case ')':
                    if (st.top() == '(')
                        st.pop();
                    else
                        return false;
                    break;
                case '}':
                    if (st.top() == '{')
                        st.pop();
                    else
                        return false;
                    break;
                case ']':
                    if (st.top() == '[')
                        st.pop();
                    else
                        return false;
                    break;
                default:
                    return false;
            }
        }
    }
    return st.empty();
}
