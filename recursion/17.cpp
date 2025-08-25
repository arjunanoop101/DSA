// Given a string containing digits from 2-9 inclusive, 
// return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()) return ans; // handle empty input
        
        string mapping[10] = {
            "", "", "abc", "def", "ghi", 
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        
        string output;
        f(digits, ans, 0, output, mapping);
        return ans;
    }

    void f(string digits, vector<string> &ans, int index, string output, string mapping[]) {
        if (index == digits.size()) { // base case
            ans.push_back(output);
            return;
        }
        
        int number = digits[index] - '0';
        string value = mapping[number];
        
        for (int i = 0; i < value.size(); i++) {
            output.push_back(value[i]);
            f(digits, ans, index + 1, output, mapping); // go to next digit
            output.pop_back();
        }
    }
};
