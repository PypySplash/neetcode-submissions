/*
1. 第一次遍歷 strs 時，將 str 排序後，檢查字典是否已經存在，若存在，儲存至這種資料結構，若不存在，增加新的 key
{'act': {'act', 'cat'}}
最後把字典中的 pair.second 部份加入到 ans 中
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> dic;
        for (string str : strs) {
            string key = str;
            ranges::sort(key);
            dic[key].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto& [key, v] : dic) {
            ans.push_back(v);
        }
        return ans;
    }
};
