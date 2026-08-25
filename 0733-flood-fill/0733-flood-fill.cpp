class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> ans;
        vector<int> vis(n);
        int x = image[sr][sc];
        if(x==color)return image;
        q.push({sr,sc});
        image[sr][sc]=color;
        vector<int> dr = {0,0,-1,1};
        vector<int> dc = {1,-1,0,0};
        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i<size;i++){
                auto[r,c] = q.front();
                q.pop();
                for(int j = 0 ; j< 4; j++){
                    int nr = r + dr[j];
                    int nc = c + dc[j];
                    if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==x){
                        q.push({nr,nc});
                        image[nr][nc]=color;
                    }
                }
            }
        }
        return image;
    }
};