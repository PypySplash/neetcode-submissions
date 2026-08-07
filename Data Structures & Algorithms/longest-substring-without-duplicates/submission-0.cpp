/*
和 Longest Repeating Character Replacement 相比，這題用 set 即可
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int left = 0, ans = 0;

        for (int i = 0; i < s.size(); i++) {
            while (st.contains(s[i])) {
                st.erase(s[left]);
                left++;
            }
            st.insert(s[i]);
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};
