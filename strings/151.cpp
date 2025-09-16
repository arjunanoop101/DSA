
//Reverse words in a string
class Solution {
public:
    string reverseWords(string s) {
        string temp="";
        string res ="";

        for(int i=0;i<s.size();i++){
            if(isalnum(s[i])){
                temp+=s[i];
            }
            if(s[i] ==' ' && !temp.empty())
            {
                res = " " + temp + res;
                temp = "";
            }
        }
        if(!temp.empty()){
            res = temp + res;
        }
        if(!res.empty() && res[0]==' '){
            res.erase(0,1);
        }
        return res;

    }
};