class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> rev(V);
        vector<int> indeg(V,0);
        for(int i = 0; i<V;i++){
            for(auto it : graph[i]){
                rev[it].push_back(i);
                indeg[i]++;
            }
        }
        queue<int> q;
        vector<int> safeN;
        for(int i = 0; i< V;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeN.push_back(node);
            for(auto it : rev[node]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }
        sort(safeN.begin(),safeN.end());
        return safeN;
    }
};