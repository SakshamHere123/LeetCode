class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V,-1);
        for(int i = 0;i<V;i++){
            if(color[i]==-1){
                if(dfs(graph,i,0,color)==false) return false;
            }
        }
        return true;
    }

    bool dfs(vector<vector<int>> & graph, int i, int col,vector<int>& color){
        color[i]=col;
        for(auto it : graph[i]){
            if(color[it]==-1){
                if(dfs(graph, it,!col,color)==false) return false;
            }
            else if(color[it]==col) return false;
            
        }
        return true;
    }
};