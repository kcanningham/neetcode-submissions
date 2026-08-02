class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int i = 0;
        int res = 0;
        for(int j = 0; j < s.length(); j++) {
            while(charSet.find(s[j]) != charSet.end()) {
                charSet.erase(s[i]);
                i++;
            }
            charSet.insert(s[j]);
            res = max(res, j - i + 1);
        }
        return res;
    }
};
