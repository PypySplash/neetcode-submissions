class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s_cnt, t_cnt; // C++ 的字典不能直接 Counter(s) 這種用法，需用 for 迴圈建構
        for (char c : s) {
            s_cnt[c]++;
        }
        for (char c : t) {
            t_cnt[c]++;
        }
        return s_cnt == t_cnt;
    }
};
