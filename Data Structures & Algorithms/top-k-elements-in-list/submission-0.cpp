class Solution {
public:
    static bool compare(const pair<int,int>& a, const pair<int,int>& b) {
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> freq;
        for(auto it : nums) {
            freq[it]++;
        }

        vector<pair <int, int>> v(freq.begin(),freq.end());
        sort(v.begin(), v.end(), compare);

        vector<int> ans;
        for(auto i = 0; i < k; i++) {
            ans.push_back(v[i].first);
        }
        return ans;
    }
};
