/*
這題可以用中心擴展法吧
遍歷 s ，讓每個字母試著當作中心，同時往左右擴展，同時更新最大值
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int ans_l = 0, ans_r = 0;

        // 奇回文串
        for (int i = 0; i < n; i++) {
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            // 迴圈結束時, l, r 處於非法位置, 故此時的長度應該為 ((r-1) - (l+1) + 1) = r - l - 1
            if (r - l - 1 > ans_r - ans_l + 1) { // 閉區間
                ans_l = l + 1;
                ans_r = r - 1;
            }
        }

        // 偶回文串
        for (int i = 0; i < n - 1; i++) {
            int l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            // 迴圈結束時, l, r 處於非法位置, 故此時的長度應該為 ((r-1) - (l+1) + 1) = r - l - 1
            if (r - l - 1 > ans_r - ans_l + 1) { // 閉區間
                ans_l = l + 1;
                ans_r = r - 1;
            }
        }
        return s.substr(ans_l, ans_r - ans_l + 1);
    }
};
