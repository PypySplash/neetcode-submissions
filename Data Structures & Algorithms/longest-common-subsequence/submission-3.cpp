class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> memo(m+1, vector<int>(n+1, -1));
        auto dfs = [&] (this auto&& dfs, int i, int j) -> int {
            if (i < 0 || j < 0) return 0;
            int& res = memo[i][j];
            if (res != -1) return res;
            // choose
            if (text1[i] == text2[j]) return res = dfs(i-1, j-1) + 1;
            return res = max(dfs(i-1, j), dfs(i, j-1));
        };
        return dfs(m-1, n-1);
    }
};
