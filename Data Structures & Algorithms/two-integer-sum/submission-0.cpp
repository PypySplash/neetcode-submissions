/*
枚舉右，維護左
當我們遇到一個數 x 時，搜尋 target - x 是否在字典中，若有，則回傳其 idx 和 對應的 idx ，若無，將 idx 存入字典，
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> dic;
        // 因為題目說一定有解，故這邊就不給上界
        for (int i = 0; ; i++) {
            int t = target - nums[i];
            if (dic.contains(t)) {
                return {dic[t], i};
            }
            dic[nums[i]] = i;
        }
        // 若給上界則需加上這行：
        // return {};
    }
};