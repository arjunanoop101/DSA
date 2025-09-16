//Remove outermost parentheses

class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int balance = 0;
        for (char c : s) {
            if (c == '(') {
                if (balance > 0) {
                    res += c;  // only add if not outermost
                }
                balance++;
            } else { // ')'
                balance--;    // decrement first
                if (balance > 0) {
                    res += c; // only add if not outermost
                }
            }
        }
        return res;
    }
};
