/*
思路：
順序不重要，出現次數也不重要 -> 用 set 存，做到 O(1) 查詢數字
遍歷 set 中的數字，若當前數字可以當作起點，則開始檢查他的下一個數，直到斷掉為止，儲存當前的最大長度，接著繼續遍歷下去尋找新的可能起點
剪枝：當前最大長度 ans * 2 > set 的長度的話，代表已經不可能找到比他長的 LCS ，跳出回圈，回傳 ans
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        for (int x : st) {
            // 只考慮可以當起點的數，故若 x - 1 存在，x 勢必無法當起點
            if (st.contains(x-1)) continue;
            // 若 x 存在，檢查 x+1 是否存在，存在的話往後繼續檢查
            int y = x + 1;
            // 回圈結束時， LCS 到 y-1
            while (st.contains(y)) {
                y++;
            }
            // ans = max(ans, y-1 - x + 1)
            ans = max(ans, y-x);
            if (ans * 2 > st.size()) break; 
        }
        return ans;
    }
};
