class Solution {
public:
    vector<int> spiralOrder(const vector<vector<int>>& matrix) {
        vector<int> ans_3;
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0, bottom = n - 1, left = 0, right = m - 1;

        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++) {
                ans_3.push_back(matrix[top][i]);
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                ans_3.push_back(matrix[i][right]);
            }
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans_3.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans_3.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ans_3;
    }
};