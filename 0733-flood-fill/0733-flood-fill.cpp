class Solution {
private:
    void dfs(int r, int c, int initialColor, int newColor, vector<vector<int>>& image) {
        int n = image.size();
        int m = image[0].size();

        // Base conditions: Out of bounds or pixel is not the initial color
        if (r < 0 || r >= n || c < 0 || c >= m || image[r][c] != initialColor) {
            return;
        }

        // Color current pixel
        image[r][c] = newColor;

        // Traverse 4 directions
        dfs(r + 1, c, initialColor, newColor, image);
        dfs(r - 1, c, initialColor, newColor, image);
        dfs(r, c + 1, initialColor, newColor, image);
        dfs(r, c - 1, initialColor, newColor, image);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        
        // Critical check: Avoid infinite recursion / stack overflow
        if (initialColor == color) return image;

        dfs(sr, sc, initialColor, color, image);
        return image;
    }
};