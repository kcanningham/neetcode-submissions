class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.length();
        if(n <= 1) return false;
        if(s[0] == ']' || s[0] == ')' || s[0] == '}') return false;
        for(char it : s) {
            if(it == '[' || it == '{' || it == '(') {
                st.push(it);
            }
            else {
                if(st.empty()) return false;

                if((it == '}' and st.top() == '{') || (it == ')' and st.top() == '(') || (it == ']' and st.top() == '[')) st.pop();
                else return false;
            }
            
        }

        if(st.empty()) return true;
        else return false;
    }
};
