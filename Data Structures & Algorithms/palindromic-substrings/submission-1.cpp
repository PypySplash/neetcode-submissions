class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();

        // 中心擴展法
        int ans = 0;
        // 奇回文串
        for (int i = 0; i < n; i++) {
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
                ans++;
            }
        } // 偶回文串
        for (int i = 0; i < n - 1; i++) {
            int l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
                ans++;
            }
        }
        return ans;
    }
};
