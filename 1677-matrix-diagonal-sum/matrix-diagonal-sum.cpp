class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int N = mat.size();
        int total = 0;
        for(int i = 0; i < N; i++){
            total += mat[i][i];
            total += mat[i][N - 1 -i];
        }

        if(N % 2 == 1){
            total -= mat[N/2][N/2];
        }

        return total;
    }
};