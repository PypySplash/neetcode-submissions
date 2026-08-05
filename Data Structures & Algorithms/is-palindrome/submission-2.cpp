class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        
        while (left < right) {
            // 忽略 non-alphanumeric characters 後可能會直接 left >= right
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            // case-insensitive 故直接 tolower()
            if (tolower(s[left]) == tolower(s[right])) {
                left++;
                right--;
            }
            else {
                return false;
            }
        }
        return true;
    }
};
