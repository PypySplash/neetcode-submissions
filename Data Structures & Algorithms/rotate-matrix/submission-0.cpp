class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 上下翻轉 + transpose
        int m = matrix.size(), n = matrix[0].size();
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
