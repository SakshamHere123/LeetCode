class Solution {
public:

    bool dfs(int src,vector<int> adj[], vector<int> &vis,vector<int> & pv){
        vis[src]= 1;
        pv[src]=1;
        for(auto it : adj[src]){
            if(!vis[it]){
                if(dfs(it,adj,vis,pv)==true) return true;
            }
            else if(pv[it]){
                return true;
            }
        }
        pv[src]=0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> vis(numCourses,0);
        vector<int> pv(numCourses,0);
        for(int i = 0; i< numCourses;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pv)==true) return false;
            }
        }
        return true;
    }
};