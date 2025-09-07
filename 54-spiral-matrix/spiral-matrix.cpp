class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty()) return res;
        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;
        while(top <= bottom && left <= right){
            //left->right
            for(int j = left; j <= right; j++){
                res.push_back(matrix[top][j]);
            }
            top++;

            //top->bottom
            for(int i = top; i <= bottom; i++){
                res.push_back(matrix[i][right]);
            }
            right--;

            //right->left
            if(top <= bottom){
                for(int j = right; j >= left; j--){
                    res.push_back(matrix[bottom][j]);
                }
                bottom--;
            }

            //bottom->top;
            if(left <= right){
                for(int i = bottom; i >= top; i--){
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return res;
    }
};