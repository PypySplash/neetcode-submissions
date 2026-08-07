/*
維護一個滑動窗口，左端點為 left, 右端點為 right ，當遇到一個字母時，將它記錄為 x ，當繼續往下遍歷時，若遇到相同字母，則 continue 若遇到不同字母，則 tmp = k -= 1
若 k < 0 則，紀錄

XXX 以上不對，若為 ABBAB 這種組合為答案時，只記錄左端點是不夠的
那麼，就維護一個字典，來判斷當前窗口的哪個字母數量最大
若 當前窗口長度 - 當前最大字母長度 > k，則縮小左端點
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> dic(26);
        int left = 0, ans = 0, mx = 0;

        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'A';
            dic[idx]++;
            mx = max(mx, dic[idx]);
            if (i - left + 1 - mx > k) {
                char out = s[left];
                dic[out - 'A']--;
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};
