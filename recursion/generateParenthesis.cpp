#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

class Solution {
public:
    void generate(vector<string>&ans,string s,int n,int open,int close){
        if(s.size() == 2*n){
            ans.push_back(s);
            return;
        }
        if(open<n){
            s.push_back('(');
            generate(ans,s,n,open+1,close);
            s.pop_back();
        }
        if(close<open){
            s.push_back(')');
            generate(ans,s,n,open,close+1);
            s.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s ;
        generate(ans,s,n,0,0);
        return ans;
    }
};