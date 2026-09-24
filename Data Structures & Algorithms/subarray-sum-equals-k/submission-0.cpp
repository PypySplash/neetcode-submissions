/*
2026.09.24 bjak oa 出現
NOTE 1: 這題的數組有負數，不具有單調性，因此不能使用滑動窗口，因為子數組和有可能隨著窗口變大而變大或變小
NOTE 2: 使用 前綴和 + 雜湊表 + 枚舉右維護左
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int pre = 0, n = nums.size(), ans = 0;
        unordered_map<int, int> dic;
        // 雜湊表先加入 0，因為等等遍歷第一個數時，要用當前的數扣掉 k 來判斷 target 有無在雜湊表中，故加入 0 是必須的
        dic[0]++;
        for (int i = 0; i < n; i++) {
            pre += nums[i];
            // 枚舉右，維護左，檢查 target 是否在雜湊表中
            if (dic.contains(pre - k)) {
                // 若在的話，雜湊表中的數量有多少，相減就會產生多少 target，故加上 dic[pre - k] 的數量
                ans += dic[pre - k];
            }
            // 檢查完後，dic[pre] 的數量 +1
            dic[pre]++;
        }
        return ans;
    }
};