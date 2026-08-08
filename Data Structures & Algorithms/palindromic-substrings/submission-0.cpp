class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();

        // 中心擴展法
        // int ans_l = 0, ans_r = 0;
        int ans = 0;
        // 奇回文串
        for (int i = 0; i < n; i++) {
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
                ans++;
            }
            // // 迴圈結束時, l, r 處於非法位置, 故此時的長度應該為 ((r-1) - (l+1) + 1) = r - l - 1
            // if (r - l - 1 > ans_r - ans_l + 1) { // 閉區間
            //     ans_l = l + 1;
            //     ans_r = r - 1;
            // }
        }

        // 偶回文串
        for (int i = 0; i < n - 1; i++) {
            int l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
                ans++;
            }
            // // 迴圈結束時, l, r 處於非法位置, 故此時的長度應該為 ((r-1) - (l+1) + 1) = r - l - 1
            // if (r - l - 1 > ans_r - ans_l + 1) { // 閉區間
            //     ans_l = l + 1;
            //     ans_r = r - 1;
            // }
        }
        return ans;
    }
};
