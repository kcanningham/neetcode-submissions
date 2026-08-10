class MinStack {
public:
    stack<int> st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        stack<int> st2;
        st2 = st;
        int minn = INT_MAX;
        while(!st2.empty()) {
            minn = min(minn, st2.top());
            st2.pop();
        }
        return minn;
    }
};
