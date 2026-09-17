class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {        
        int m = grid.size();
        int n = grid[0].size();
        int c = 0;
        queue<pair<int,int>> q;
        for(int i = 0; i<m;i++){
            if(grid[i][0]==1){
                grid[i][0]=0;
                q.push({i,0});
            }
            if(grid[i][n-1]==1){
                grid[i][n-1]=0;
                q.push({i,n-1});
            }
        }
        for(int i = 0; i<n;i++){
            if(grid[0][i]==1){
                grid[0][i]=0;
                q.push({0,i});
            }
            if(grid[m-1][i]==1){
                grid[m-1][i]=0;
                q.push({m-1,i});
            }
        }
        vector<int> dr = {0,0,-1,1};
        vector<int> dc = {1,-1,0,0};
        while(!q.empty()){
            auto[r,c]=q.front();
            q.pop();
            for(int i = 0; i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1){
                    grid[nr][nc]=0;
                    q.push({nr,nc});
                }
            }
        }
        for(int i = 0; i<m;i++){
            for(int j = 0; j<n;j++){
                if(grid[i][j]==1){
                    c++;
                }
            }
        }
        return c;
    }
};