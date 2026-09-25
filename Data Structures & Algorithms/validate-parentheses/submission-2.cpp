# include <stack>
/*
進階技巧：遇到 (, {, [ 時，把 ), }, ] 推入棧中，而不是推入原本的 (, {, [, 這樣後面檢查時只需檢查 if c == st.top() 即可！就不用分成三種情況
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(') st.emplace(')');
            else if (c == '{') st.emplace('}');
            else if (c == '[') st.emplace(']');
            else {
                if (st.empty() || st.top() != c) return false;
                st.pop();
            }
        }
        // 若最後為空表示都是合法的括號，不為空的話表示有不合法的括號
        return st.empty();



        // for (char c : s) {
        //     if (c == '(' || c == '{' || c == '[') {
        //         st.emplace(c);
        //     }
        //     else if (c == ')') {
        //         if (!st.empty() && st.top() == '(') {
        //             st.pop();
        //         } else {
        //             return false;
        //         }
        //     } else if (c == '}') {
        //         if (!st.empty() && st.top() == '{') {
        //             st.pop();
        //         } else {
        //             return false;
        //         }
        //     } else { // if (c == ']')
        //         if (!st.empty() && st.top() == '[') {
        //             st.pop();
        //         } else {
        //             return false;
        //         }
        //     }
        // }
        // 若最後為空表示都是合法的括號，不為空的話表示有不合法的括號
        // return st.empty();
    }
};
