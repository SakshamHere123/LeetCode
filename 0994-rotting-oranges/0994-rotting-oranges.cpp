class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;
        for(int i = 0 ; i<n;i++){
            for(int j = 0; j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1) fresh++;
            }
        }
        int min = 0;
        vector<int> dr = {1,-1,0,0};
        vector<int> dc = {0,0,-1,1};
        while(!q.empty() && fresh>0){
            int size = q.size();
            for(int k = 0; k< size;k++){
                auto[r,c]=q.front();
                q.pop();
                for(int i = 0;i<4;i++){
                    int newr = r + dr[i];
                    int newc = c + dc[i];

                    if(newr>= 0 && newr <n && newc>=0 && newc < m && grid[newr][newc]==1){
                        grid[newr][newc]=2;
                        q.push({newr,newc});
                        fresh--;
                    }
                }
            }
            min++;
        }
        return fresh==0?min:-1;
    }
};