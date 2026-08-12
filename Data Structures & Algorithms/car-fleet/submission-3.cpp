class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if(n == 0) return 0;
        stack<double> st;
        map<int, int, greater<int>> mp; 
        for(int i = 0; i < n; i++) {
            mp[position[i]] = speed[i];
        }
        
        // for(auto it : mp) {
        //     cout<<it.first<<" "<<it.second<<endl;
        // }

        for(auto it : mp) {
            double time = (double)(target - it.first)/it.second;
            if(st.empty() || st.top() < time) st.push(time);
        }
        return st.size();
    }
};
