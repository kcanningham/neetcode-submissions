class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.length();
        int n = s2.length();
        if (n < k) return false;
        string sort_s1 = s1;
        sort(sort_s1.begin(), sort_s1.end());
        int i = 0;
        string perm = "";
        for(int j = 0; j < k; j++) {
            perm += s2[j];
        }

        for(int j = k; j < n; j++) {
            string sort_perm = perm;
            sort(sort_perm.begin(), sort_perm.end());
            if(sort_perm == sort_s1) return true;
            perm.erase(0,1);
            perm += s2[j];
        }
        string sort_perm = perm;
        sort(sort_perm.begin(), sort_perm.end());
        if(sort_perm == sort_s1) return true;
        return false;
    }
};
