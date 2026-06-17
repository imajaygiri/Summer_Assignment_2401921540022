#include <stack>
#include <utility>
using namespace std;
class MinStack {
    stack<pair<int, int>> st;

   public:
    MinStack() {
    }

    void push(int val) {
        pair<int, int> p;
        int min;
        if (st.empty()) {
            min = val;
        } else {
            if (st.top().second > val) {
                min = val;
            } else {
                min = st.top().second;
            }
        }
        p = {val, min};
        st.push(p);
    }
    int top() {
        return st.top().first;
    }
    int getMin() {
        return st.top().second;
    }
    void pop() {
        st.pop();
    }
};
