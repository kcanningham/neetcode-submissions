class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set <int> s;
        for(auto it : nums) {
            s.insert(it);
        }
        
        for(int i : s) {
            if(s.find(i - 1) == s.end()) {
                int max_length = 1;
                while(s.find(i + max_length) != s.end()) {
                    max_length += 1;
                }
                ans = max(max_length, ans);
            }
        }
        return ans;
    }
};
