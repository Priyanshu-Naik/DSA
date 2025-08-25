class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int newColor, int oldColor){
        int n = image.size();
        int m = image[0].size();

        if(r < 0 || r >= n || c < 0 || c >= m || image[r][c] != oldColor){
            return;
        }

        image[r][c] = newColor;

        dfs(image, r+1, c, newColor, oldColor);
        dfs(image, r-1, c, newColor, oldColor);
        dfs(image, r, c+1, newColor, oldColor);
        dfs(image, r, c-1, newColor, oldColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        if(oldColor == color) return image;

        dfs(image, sr, sc, color, oldColor);
        return image;
    }
};