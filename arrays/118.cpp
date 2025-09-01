// Pascal's Triangle

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(generateRows(i));
        }

        return ans;
    }

    vector<int> generateRows(int row){
        vector<int>list;
        list.push_back(1);
        long long ans=1;
        for(int i=1;i<row;i++){
            ans = ans * (row - i);
            ans =  ans / i;
            list.push_back(ans);
        }
        return list;
    }
};