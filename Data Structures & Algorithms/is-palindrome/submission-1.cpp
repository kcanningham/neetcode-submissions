class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        string result = "";
        for (char ch : s) {
            if ((ch >= 'a' && ch <= 'z') ||
                (ch >= 'A' && ch <= 'Z') ||
                (ch >= '0' && ch <= '9')) {
                    result += tolower(ch);
            }
        }
        cout<<result;

        int n = result.length();
        
        for(int i = 0 , j = n - 1; i <= j; i++, j--) {
            if(result[i] != result[j]) return false;
        }
        return true;
        
    }
};
