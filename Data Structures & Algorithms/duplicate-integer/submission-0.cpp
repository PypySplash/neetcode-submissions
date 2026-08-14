class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for (int x : nums) {
            if (st.contains(x)) {
                return true;
            }
            st.insert(x);
        }
        return false;
    }
};