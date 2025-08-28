//Spiral matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0;
        int right = matrix[0].size() - 1;
        int top = 0;
        int bottom = matrix.size() - 1;
        vector<int> ans;

        while (top <= bottom && left <= right) {
            // Traverse from left to right (top row)
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;

            // Traverse from top to bottom (right column)
            if (top <= bottom) {
                for (int i = top; i <= bottom; i++) {
                    ans.push_back(matrix[i][right]);
                }
                right--;
            }

            // Traverse from right to left (bottom row)
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // Traverse from bottom to top (left column)
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ans;
    }
};
