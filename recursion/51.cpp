// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the 
// n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n, '.');
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        int col = 0;
        nqueen(col,ans,board, n);
        return ans;
    }

    void nqueen(int col,vector<vector<string>>&ans,vector<string>&board,int n){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col] = 'Q';
                nqueen(col+1,ans,board,n);
                board[row][col] = '.';
            }
        }

    }

    bool isSafe(int row, int col, vector<string>&board, int n){
        //check left side
        for(int i=0;i<col;i++){
            if(board[row][i]=='Q'){
                return false;
            }
        }

        // check left above diagonal
        for(int i=row,j=col; i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }

        //check left below diagonal
        for(int i=row,j=col;j>=0 && i<n;i++,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }

        return true;

    }
};