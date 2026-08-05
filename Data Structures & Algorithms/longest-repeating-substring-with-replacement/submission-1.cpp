class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int i = 0, res = 0, maxf = 0;
        for(int j = 0; j < s.length(); j++) {
            freq[s[j]]++;
            maxf = max(maxf, freq[s[j]]);
            while((j - i + 1) - maxf > k) {
                freq[s[i]]--;
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};
