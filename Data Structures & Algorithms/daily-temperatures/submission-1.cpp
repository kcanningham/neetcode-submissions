class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> nge(n, 0);
        stack<int> ms;
        for(int i = n - 1; i >= 0; i--) {
            while(!ms.empty() && temperatures[ms.top()] <= temperatures[i]) {
                ms.pop();
            }

            if(ms.empty()) nge[i] = 0;
            else nge[i] = ms.top() - i;
            
            ms.push(i);
        }
        return nge;
    }
};
