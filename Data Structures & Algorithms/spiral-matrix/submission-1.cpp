/*
維護四個邊界指針：
top = 0
bottom = n - 1
left = 0
right = m - 1
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> ans;
        int top = 0, bottom = n - 1, left = 0, right = m - 1;
        while (left <= right && top <= bottom) {
            // 1. left -> right
            for (int col = left; col <= right; col++) {
                ans.push_back(matrix[top][col]);
            }
            top++;
            // 2. up -> down
            for (int row = top; row <= bottom; row++) {
                ans.push_back(matrix[row][right]);
            }
            right--;
            // 3. right -> left (need to ensure top <= bottom, 因為可能只有一列)
            if (top <= bottom) {
                for (int col = right; col >= left; col--) {
                    ans.push_back(matrix[bottom][col]);
                }
                bottom--;
            }
            // 4. down -> up (need to ensure left <= right)
            if (left <= right) {
                for (int row = bottom; row >= top; row--) {
                    ans.push_back(matrix[row][left]);
                }
                left++;
            }
        }
        return ans;
    }
};
